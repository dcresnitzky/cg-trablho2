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
float sensibilidade = 0.001f;

// Tamanho do Viewport
int width;
int height;

// -----------------------------------
//             MAIN
// -----------------------------------

int main(int argc, char **argv) {

    // Inicializacao do GLUT 
    glutInit(&argc, argv);
    // Cria janela utilizando Profundidade, Double Buffer e modo de cores RGBA.
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    // Cria Janela e coloca no modo tela cheia.
    glutCreateWindow("Traffic");
    glutFullScreen();
    //
    // -----------------------------------
    //             GLUT.CPP
    // -----------------------------------
    //
    // Cria a cena com a funcao renderScene
    glutDisplayFunc(renderScene);
    // Callback para redimensionamento de janela
    glutReshapeFunc(changeSize);
    // Prepara para a nova renderizacao
    glutIdleFunc(glutPostRedisplay);
    //
    // -----------------------------------
    //             INPUT.CPP
    // -----------------------------------
    //
    // Desabilita o cursor do mouse.
    glutSetCursor(GLUT_CURSOR_NONE);
    //
    // Ignora o callback para repeticao de teclas
    glutIgnoreKeyRepeat(1);
    // Callback para as teclas do teclado
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    //
    // here are the two new functions
    //glutMouseFunc(mouseButton);
    glutMotionFunc(passiveMotion);
    glutPassiveMotionFunc( passiveMotion );
    
    //
    // OpenGL init
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    //
    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}