// -----------------------------------
//             TECLADO
// -----------------------------------

void processNormalKeys(unsigned char key, int xx, int yy) {

    switch (key) {
        case 27:
            exit(0);
            break;
        case 'z':
            capture = !capture;
            break;
    }
}

void pressKey(int key, int xx, int yy) {

    switch (key) {
        case GLUT_KEY_UP : deltaMove = 0.5f; break;
        case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
    }
}

void releaseKey(int key, int x, int y) {

    switch (key) {
        case GLUT_KEY_UP :
        case GLUT_KEY_DOWN : deltaMove = 0;break;
    }
}

// -----------------------------------
//             MOUSE
// -----------------------------------

void passiveMotion( int x, int y ){

    static bool warped = false;
    if( warped )
    {
        warped = false;
        return;
    }

    if( capture )
    {
        warped = true;
        int w = glutGet( GLUT_WINDOW_WIDTH );
        int h = glutGet( GLUT_WINDOW_HEIGHT );
        glutWarpPointer( w / 2, h / 2 );

        int dx = ( w / 2 ) - x;
        int dy = ( h / 2 ) - y;
        
        deltaAngle = (x - xOrigin) * 0.001f;

        // update camera's direction
        lx = sin(angle + deltaAngle);
        lz = -cos(angle + deltaAngle);
    }
    else
    {
        printf("a%i a%i ",x,y);
    }
}

void mouseMove(int x, int y) {

    // this will only be true when the left button is down
    if (xOrigin >= 0) {

        // update deltaAngle
        deltaAngle = (x - xOrigin) * 0.001f;

        // update camera's direction
        lx = sin(angle + deltaAngle);
        lz = -cos(angle + deltaAngle);
    }
}

void mouseButton(int button, int state, int x, int y) {

    // only start motion if the left button is pressed
    if (button == GLUT_LEFT_BUTTON) {

        // when the button is released
        if (state == GLUT_UP) {
            angle += deltaAngle;
            xOrigin = -1;
        }
        else  {// state = GLUT_DOWN
            xOrigin = x;
        }
    }
}
