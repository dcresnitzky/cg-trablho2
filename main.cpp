/*
- Objetos em 3-D
- Interação com o usuário
- Mudança das Condições de Câmera
- Zoom in e Zoom out
- Cores e Iluminação
- Transformações de Translação, Rotação e Escala
- Movimento
- Projeções
*/
#include "traffic.h"

float angle = 0.0f;

// actual vector representing the camera's direction
float lx=0.0f;
float lz=-1.0f;

// XZ position of the camera
float x=0.0f;
float z=5.0f;

// the key states. These variables will be zero when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

// Captura do mouse para mover a camera.
bool capture = true;


// -----------------------------------
//             MAIN
// -----------------------------------

int main(int argc, char **argv) {

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("Traffic");
    glutFullScreen();
    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);

    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);

    // here are the two new functions
    //glutMouseFunc(mouseButton);
    //glutMotionFunc(mouseMove);
    glutPassiveMotionFunc( passiveMotion );

    // OpenGL init
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}