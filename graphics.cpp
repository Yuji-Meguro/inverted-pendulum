#include"graphics.hpp"
#include"define.hpp"
#include"simulation.hpp"

#include<GL/glut.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

#include<iostream>

extern pole_assignment InvPend;

void idle(void){
    glutPostRedisplay();
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //地面を描く
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-1.0, GROUND_HEIGHT-0.01);
    glVertex2d( 1.0, GROUND_HEIGHT-0.01);
    glVertex2d(-1.0, GROUND_HEIGHT);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d( 1.0, GROUND_HEIGHT);
    glVertex2d(-1.0, GROUND_HEIGHT);
    glVertex2d( 1.0, GROUND_HEIGHT-0.01);
    glEnd();

    //棒を描く
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-BAR_WIDTH/2*cos(InvPend.Get_theta()), GROUND_HEIGHT-BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glVertex2d( BAR_WIDTH/2*cos(InvPend.Get_theta()), GROUND_HEIGHT+BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glVertex2d(-BAR_WIDTH/2*cos(InvPend.Get_theta())-BAR_LENGTH*sin(InvPend.Get_theta()), GROUND_HEIGHT-BAR_WIDTH/2*sin(InvPend.Get_theta())+BAR_LENGTH*cos(InvPend.Get_theta()));
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d( BAR_WIDTH/2*cos(InvPend.Get_theta())-BAR_LENGTH*sin(InvPend.Get_theta()), GROUND_HEIGHT+BAR_LENGTH*cos(InvPend.Get_theta())+BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glVertex2d(-BAR_WIDTH/2*cos(InvPend.Get_theta())-BAR_LENGTH*sin(InvPend.Get_theta()), GROUND_HEIGHT+BAR_LENGTH*cos(InvPend.Get_theta())-BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glVertex2d( BAR_WIDTH/2*cos(InvPend.Get_theta()), GROUND_HEIGHT+BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glEnd();

    //円を描く
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for(int i=0;i<PART;i++){
        double rate=(double)i/PART;
        double x= RADIUS*cos(2.0*M_PI*rate);
        double y= RADIUS*sin(2.0*M_PI*rate);
        glVertex3d(x-BAR_LENGTH*sin(InvPend.Get_theta()), y+GROUND_HEIGHT+BAR_LENGTH*cos(InvPend.Get_theta()), 0.0);
    }
    glEnd();

    glutSwapBuffers();
    //   glFlush();

    RungeKutta(InvPend,DT);
    std::cout<< InvPend.Get_state()<<std::endl;
    std::cout<<std::endl;
}

void mouse(int button, int state, int x, int y){
    switch (button) {
    case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN) {
        /* アニメーション開始 */
        glutIdleFunc(idle);
    }
    else {
        /* アニメーション停止 */
        glutIdleFunc(0);
    }
    break;
    case GLUT_RIGHT_BUTTON:
    if (state == GLUT_DOWN) {
        /* コマ送り (1ステップだけ進める) */
        glutPostRedisplay();
    }
    break;
    default:
    break;
    }
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'q':
        case 'Q':
        case '\033':  /* '\033' は ESC の ASCII コード */
            exit(0);
        default:
            break;
    }
}

void graphics(int argc,char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
}
