// -----------------------------------
//             TECLADO
// -----------------------------------

void processNormalKeys(unsigned char key, int xx, int yy) {

    switch (key) {
    	// Esc
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
        int metade_width = width/2;
        int metade_height = height/2;
        if ( x > metade_width ){
        	deltaAngle += sensibilidade;
        }
        else {
        	deltaAngle = -sensibilidade;

        }
        angle += deltaAngle;
	    // update camera's direction
	    lx = sin(angle + deltaAngle);
	    lz = -cos(angle + deltaAngle);

        // Trava o mouse no centro da tela
        glutWarpPointer( width/2 , height/2 );
        
    }
    else
    {
    	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    }
}

void mouseMove(int x, int y) {
   
        int metade_width = width/2;
        int metade_height = height/2;
        if ( x > metade_width ){
        	deltaAngle += sensibilidade;
        }
        else {
        	deltaAngle = -sensibilidade;

        }
        angle += deltaAngle;
	    // update camera's direction
	    lx = sin(angle + deltaAngle);
	    lz = -cos(angle + deltaAngle);

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
