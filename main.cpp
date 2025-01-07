#include <iostream>
#include <stdlib.h>
#include <gl/glut.h>
#include <gl/gl.h>

int press_x, press_y;
int release_x, release_y;
float x_angle = 0.0;
float y_angle = 0.0;
float scale_size = 1;

int xform_mode = 0;

#define XFORM_NONE    0
#define XFORM_ROTATE  1 
#define XFORM_SCALE 2

int draw_axes = 0;
int angle = 0;
float r_color = 1;
float g_color = 1;
int ani = 0;
int timer = 50;

void RenderString(GLdouble x, GLdouble y, const std::string &string)
{
    glColor3d(1.0, 1.0, 1.0);
    glRasterPos2d(x, y);
    for (int n=0; n<string.size(); ++n) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, string[n]);
    }
}

void draw_cube(float r, float g, float b)
{

  if (draw_axes == 1)
    {
        glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(2,0,0);
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,2);
        glEnd();
    }
  glColor3f(r, g, b);
  glutSolidCube(1.0);
  glColor3f(0,0,0);
  glLineWidth(2);
  glutWireCube(1.05);
  glLineWidth(1);
}


void windmill()
{

  draw_cube(0.5,0.35,0.05);

  glPushMatrix();
  glTranslatef(.65, 0, 0);
  glRotatef((float)angle,1,0,0);
  glScalef(0.01, 5, 0.3);
  draw_cube(0.752941,0.752941,0.752941);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(.65, 0, 0);
  glRotatef((float)angle,1,0,0);
  glScalef(0.3, 0.3, 0.3);
  draw_cube(0,0,0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(.65, 0, 0);
  glRotatef((float)angle+90,1,0,0);
  glScalef(0.01, 5, 0.3);
  draw_cube(0.752941,0.752941,0.752941);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,-1.5, 0);
  glScalef(0.5, 2, 0.5);
  draw_cube(0.5,0.35,0.05);
  glPopMatrix();

}

void house()
{
    if (ani==1)
    {
        r_color=0.2;
        g_color=0.2;
    }
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.35, 0.05);
    glVertex3f( 1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0,  1.0);
    glVertex3f( 1.0, 1.0,  1.0);

    glColor3f(0.5, 0.35, 0.05);
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f(-1.0, -1.0,  1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);

    glColor3f(0.3, 0.3, 0.3);
    glVertex3f( 3.0, -0.9,  3.0);
    glVertex3f(-3.0, -0.9,  3.0);
    glVertex3f(-3.0, -0.9, -3.0);
    glVertex3f( 3.0, -0.9, -3.0);

    glColor3f(0.5, 0.35, 0.05);
    glVertex3f( 1.0,  1.0, 1.0);
    glVertex3f(-1.0,  1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f( 1.0, -1.0, 1.0);

    glColor3f(0.5, 0.35, 0.05);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);

    glColor3f(0.5, 0.35, 0.05);
    glVertex3f(-1.0,  1.0,  1.0);
    glVertex3f(-1.0,  1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0,  1.0);

    glColor3f(0.5, 0.35, 0.05);
    glVertex3f(1.0,  1.0, -1.0);
    glVertex3f(1.0,  1.0,  1.0);
    glVertex3f(1.0, -1.0,  1.0);
    glVertex3f(1.0, -1.0, -1.0);

    glColor3f(r_color,g_color , 0.05);
    glVertex3f( 0.5,  0.5, 1.01);
    glVertex3f(-0.5,  0.5, 1.01);
    glVertex3f(-0.5, -0.5, 1.01);
    glVertex3f( 0.5, -0.5, 1.01);

    glColor3f(r_color, g_color, 0.05);
    glVertex3f(1.01,  0.5, -0.5);
    glVertex3f(1.01,  0.5,  0.5);
    glVertex3f(1.01, -0.5,  0.5);
    glVertex3f(1.01, -0.5, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.02, 0.5, 0.0);
    glVertex3f(1.02, -0.5, 0.0);
    glVertex3f(1.02, 0.0, -0.5);
    glVertex3f(1.02, 0.0, 0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 1.02);
    glVertex3f(0.0, -0.5, 1.02);
    glVertex3f(0.5, 0.0, 1.02);
    glVertex3f(-0.5, 0.0, 1.02);
    glEnd();

    glTranslatef(0.0, 2.0, 0.0);

    glBegin(GL_TRIANGLES);

    glColor3f(0.5, 0.0, 0.0);
    glVertex3f( 0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    glColor3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);

    glColor3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);

    glColor3f(0.5, 0.0, 0.0);
    glVertex3f( 0.0, 1.0, 0.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0, 1.0);
    glEnd();
}

void display()
{
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.05, 0.05, 0.05, 1.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1, .1, 100);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0,0,50,0,0,0,0,1,0);

  glRotatef(x_angle, 0, 1,0);
  glRotatef(y_angle, 1,0,0);
  glScalef(scale_size, scale_size, scale_size);

  RenderString(-25, 25, "Press A to control wind");
  RenderString(-25, 22, "Click and drag mouse to change viewing camera position");

    glColor3f(0.0, 0.2, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-100.0, -3.8, -100.0);
    glVertex3f(-100.0,  -3.8, 100.0);
    glVertex3f( 100.0,  -3.8, 100.0);
    glVertex3f( 100.0, -3.8, -100.0);
	glEnd();
	glColor3f(0.0, 0.0, 0.2);
	glBegin(GL_QUADS);
    glVertex3f(12.0, -3.7, -100.0);
    glVertex3f(12.0,  -3.7, 100.0);
    glVertex3f( 100.0,  -3.7, 100.0);
    glVertex3f( 100.0, -3.7, -100.0);
	glEnd();

    glPushMatrix();
    glTranslatef(-5, -2.8, 15.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, -2.8, 0.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-13, -2.8, 30.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, -2.8, -10.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30, -2.8, -10.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, -2.8, -15.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40, -2.8, -5.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30, -2.8, -20.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35, -2.8, -30.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, -2.8, -25.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, -2.8, 10.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50, -2.8, 21.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60, -2.8, 30.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-55, -2.8, -40.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-45, -2.8, 40.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-32, -2.8, 20.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-31, -2.8, 35.0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-1.3,0);
    windmill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-1.3,10);
    windmill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-1.3,5);
    windmill();
    glPopMatrix();

    glutSwapBuffers();
}

void mymouse(int button, int state, int x, int y)
{
  if (state == GLUT_DOWN)
    {
        press_x = x; press_y = y;
        if (button == GLUT_LEFT_BUTTON)
            xform_mode = XFORM_ROTATE;
        else if (button == GLUT_RIGHT_BUTTON)
            xform_mode = XFORM_SCALE;
  }
  else if (state == GLUT_UP) {
	  xform_mode = XFORM_NONE;
  }
}

void myidle(int val) {

  if (ani == 0) glutTimerFunc(timer,myidle,0);

  angle = (angle + 10) % 360;
  r_color=1;
  g_color=1;
  glutPostRedisplay();

}


void mymotion(int x, int y)
{
      if (xform_mode==XFORM_ROTATE) {
      x_angle += (x - press_x)/5.0;
      if (x_angle > 180) x_angle -= 360;
      else if (x_angle <-180) x_angle += 360;
      press_x = x;

      y_angle += (y - press_y)/5.0;
      if (y_angle > 180) y_angle -= 360;
      else if (y_angle <-180) y_angle += 360;
      press_y = y;
    }
	  else if (xform_mode == XFORM_SCALE){
      float old_size = scale_size;
      scale_size *= (1+ (y - press_y)/60.0);
      if (scale_size <0) scale_size = old_size;
      press_y = y;
    }
	glutPostRedisplay();
}


void mykey(unsigned char key, int x, int y)
{
        switch(key) {
	case 'q': exit(1);
	  break;
	case 'a':
	  if (ani ==1 ) {ani = 0; glutTimerFunc(timer, myidle,0);   }
	  else if (ani ==0 ) {ani = 1;   }
	break;

	}
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
  glutInitWindowSize(600,600);
  glutCreateWindow("Windmill");
  glutDisplayFunc(display);
  glutMouseFunc(mymouse);
  glutMotionFunc(mymotion);
  glutKeyboardFunc(mykey);
  glutTimerFunc(timer,myidle,0);
  glutMainLoop();
}
