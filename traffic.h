// OpenGL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
// Math 
#include <math.h>
// Stdlib
#include <stdlib.h>

// Stdio para escrever no console.
#include <stdio.h>
// -----------------------------------
//             CAMERA.CPP
// -----------------------------------

// angle of rotation for the camera direction
extern float angle;

// actual vector representing the camera's direction
extern float lx;
extern float lz;

// XZ position of the camera
extern float x,z;

// -----------------------------------
//             INPUT.CPP
// -----------------------------------

// the key states. These variables will be zero when no key is being presses
extern float deltaAngle;
extern float deltaMove;
extern int xOrigin;

// Captura do mouse para mover a camera.
extern bool capture;


// Camera
#include "camera.cpp"
// Teclado/Mouse
#include "input.cpp"
// Carros
#include "draws/carros.cpp"
// Construcoes
#include "draws/construcoes.cpp"
// Misc
#include "draws/misc.cpp"
// Funcoes do Glut
#include "glut.cpp"

//glut.cpp
//void changeSize(int w, int h);
//void renderScene(void);
//camera.cpp
//void computePos(float deltaMove);
//input.cpp
//void processNormalKeys(unsigned char key, int xx, int yy);
//void pressKey(int key, int xx, int yy);
//void releaseKey(int key, int x, int y);
//void passiveMotion( int x, int y );
