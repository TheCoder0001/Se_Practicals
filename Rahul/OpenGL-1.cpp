#include<GL/glut.h>

void mydisplay()
{
   // Clear color and depth buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glLoadIdentity();
   
   // Set up the view transformation
   glTranslatef(0.0,0.0,-10.0);     // Move the object away from the viewer
   glRotatef(45.0,1.0,0.0,0.0);     // Rotate around the x-axis
   glRotatef(-45.0,0.0,1.0,0.0);    // Rotate around the y-axis
   //glScalef(2.0, 2.0, 0.0)

   // Draw a cube using GL_QUADS
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
   
   // Flush the rendering pipeline
   glFlush();
}

void init()
{
  // Set clear color and enable depth testing
  glClearColor(0.0,0.0,0.0,0.5);
  glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h)
{
   // Set up the viewport and projection matrix
   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60,1,2.0,50.0); // Perspective projection
   glMatrixMode(GL_MODELVIEW);  
}

int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("3D transformations");
  glutDisplayFunc(mydisplay);
  glutReshapeFunc(reshape);
  init();
  glutMainLoop();
}
