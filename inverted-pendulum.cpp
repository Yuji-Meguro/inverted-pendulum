#include<iostream>
#include<GL/glut.h>
#include<GL/glut.h>
#include<math.h>

#define GROUND_HEIGHT -0.9//地面の高さ
#define PART 50//円の分割数
#define RADIUS 0.2//円の半径
#define BAR_WIDTH 0.1//棒の幅
#define BAR_LENGTH 1.0//棒の長さ

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);

  //地面を描く
  glColor3d(0.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2d(-1.0, -1.0);
  glVertex2d( 1.0, -1.0);
  glVertex2d(-1.0, GROUND_HEIGHT);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex2d( 1.0, GROUND_HEIGHT);
  glVertex2d(-1.0, GROUND_HEIGHT);
  glVertex2d( 1.0, -1.0);
  glEnd();

  //棒を描く
  glColor3d(0.0, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2d(-BAR_WIDTH/2, GROUND_HEIGHT);
  glVertex2d( BAR_WIDTH/2, GROUND_HEIGHT);
  glVertex2d(-BAR_WIDTH/2, GROUND_HEIGHT+BAR_LENGTH);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex2d( BAR_WIDTH/2, GROUND_HEIGHT+BAR_LENGTH);
  glVertex2d(-BAR_WIDTH/2, GROUND_HEIGHT+BAR_LENGTH);
  glVertex2d( BAR_WIDTH/2, GROUND_HEIGHT);
  glEnd();

  //円を描く
  glColor3d(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  for(int i=0;i<PART;i++){
      double rate=(double)i/PART;
      double x= RADIUS*cos(2.0*M_PI*rate);
      double y= RADIUS*sin(2.0*M_PI*rate);
      glVertex3d(x, y+GROUND_HEIGHT+BAR_LENGTH, 0.0);
  }
  glEnd();

  glFlush();
}

void vizualize(int argc,char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
}

int main(int argc,char *argv[]){
    vizualize(argc, argv);
    return 0;
}