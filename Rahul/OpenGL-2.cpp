#include <GL/glut.h>

float angle_f = 0.0;    // Initial rotation angle
float scale_f = 0.0;    // Initial scaling factor
float trans_f = 20;     // Initial translation value

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();  // Resets modelview matrix

    // Apply transformations
    glTranslatef(trans_f, trans_f, -40);   // Translation
    glScalef(scale_f, scale_f, scale_f);    // Scaling
    glRotatef(angle_f, 1.0, 0.0, 0.0);      // Rotation around x-axis
    glRotatef(angle_f, 0.0, 1.0, 0.0);      // Rotation around y-axis
    glRotatef(angle_f, 0.0, 0.0, 1.0);      // Rotation around z-axis

    glBegin(GL_QUADS);
	// Front face (red)
   glColor3f(1.0,0.0,0.0);
   glVertex3f(-1.0,1.0,1.0);
   glVertex3f(-1.0,-1.0,1.0);
   glVertex3f(1.0,-1.0,1.0);
   glVertex3f(1.0,1.0,1.0);
    
   // Back face (green)
   glColor3f(0.0,1.0,0.0);
   glVertex3f(1.0,1.0,-1.0);
   glVertex3f(1.0,-1.0,-1.0);
   glVertex3f(-1.0,-1.0,-1.0);
   glVertex3f(-1.0,1.0,-1.0);
    
   // Right face (blue)
   glColor3f(0.0,0.0,1.0);
   glVertex3f(1.0,1.0,1.0);
   glVertex3f(1.0,-1.0,1.0);
   glVertex3f(1.0,-1.0,-1.0);
   glVertex3f(1.0,1.0,-1.0);
    
   // Left face (yellow)
   glColor3f(1.0,1.0,0.0);
   glVertex3f(-1.0,1.0,-1.0);
   glVertex3f(-1.0,-1.0,-1.0);
   glVertex3f(-1.0,-1.0,1.0);
   glVertex3f(-1.0,1.0,1.0);
    
   // Top face (cyan)
   glColor3f(0.0,1.0,1.0);
   glVertex3f(-1.0,1.0,-1.0);
   glVertex3f(-1.0,1.0,1.0);
   glVertex3f(1.0,1.0,1.0);
   glVertex3f(1.0,1.0,-1.0);
    
   // Bottom face (magenta)
   glColor3f(1.0,0.0,1.0);
   glVertex3f(-1.0,-1.0,-1.0);
   glVertex3f(-1.0,-1.0,1.0);
   glVertex3f(1.0,-1.0,1.0);
   glVertex3f(1.0,-1.0,-1.0);
   
    glEnd();

    // Increment transformations for animation
    angle_f += 0.5;    // Rotation speed
    scale_f += 0.004;   // Scaling speed
    trans_f -= 0.01;    // Translation speed

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.5);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  // Resets projection matrix
    gluPerspective(60, 1, 0.1, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);  // 60 frames per second
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Transformations and Animation");
    glutDisplayFunc(mydisplay);
    glutReshapeFunc(reshape);
    init();
    glutTimerFunc(0, timer, 0);  // Start the timer
    glutMainLoop();
    return 0;
}
