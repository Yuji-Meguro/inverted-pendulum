#include<GL/glut.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>

#include<stdlib.h>

#define GROUND_HEIGHT -0.9//地面の高さ
#define PART 50//円の分割数
#define RADIUS 0.2//円の半径
#define BAR_WIDTH 0.1//棒の幅
#define BAR_LENGTH 1.0//棒の長さ
#define G 9.8//重力加速度

class inverted_pendulum{
    public:
        inverted_pendulum();
        ~inverted_pendulum();
    private:
    //パラメータ
    double l_pen;//棒の長さ
    double m_pen;//重りの重さ
    double theta_pen;//角度
    double dtheta_pen;//角速度
};

void idle(void){
    glutPostRedisplay();
}


void display(void){
    static int hoge=0;/*長さ変換*/

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-BAR_WIDTH/2, GROUND_HEIGHT);
    glVertex2d( BAR_WIDTH/2, GROUND_HEIGHT);
    glVertex2d(-BAR_WIDTH/2, GROUND_HEIGHT+BAR_LENGTH+(double)hoge/200);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d( BAR_WIDTH/2, GROUND_HEIGHT+BAR_LENGTH+(double)hoge/200);
    glVertex2d(-BAR_WIDTH/2, GROUND_HEIGHT+BAR_LENGTH+(double)hoge/200);
    glVertex2d( BAR_WIDTH/2, GROUND_HEIGHT);
    glEnd();

    //円を描く
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for(int i=0;i<PART;i++){
        double rate=(double)i/PART;
        double x= RADIUS*cos(2.0*M_PI*rate);
        double y= RADIUS*sin(2.0*M_PI*rate);
        glVertex3d(x, y+GROUND_HEIGHT+BAR_LENGTH+(double)hoge/200, 0.0);
    }
    glEnd();

    glutSwapBuffers();
    //   glFlush();

    if(++hoge >=100){
        hoge=0;
    }
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

void vizualize(int argc,char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
}


int main(int argc,char *argv[]){
    vizualize(argc, argv);
    return 0;
}