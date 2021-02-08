#include<GL/glut.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>

#include<stdlib.h>

#include<Eigen/Dense>

#define GROUND_HEIGHT -0.5//地面の高さ
#define PART 50//円の分割数
#define RADIUS 0.2//円の半径
#define BAR_WIDTH 0.1//棒の幅
#define BAR_LENGTH 0.4//棒の長さ
#define G 9.8//重力加速度
#define DT 0.1//微小時間

#define M 1.0
#define L 1.0

#define THETA_PENDULUM0 0.0
#define DTHETA_PENDULUM0 0.1

class inverted_pendulum{
    private:
        //パラメータ
        double theta_pendulum;//角度
        double dtheta_pendulum;//角速度
    public:
        inverted_pendulum();
        ~inverted_pendulum();
        double Get_theta();
        double Get_dtheta();
        Eigen::Vector2d Get_state();
        void Set_theta(double&);
        void Set_dtheta(double&);
        void Set_state(Eigen::Vector2d&);
};

inverted_pendulum::inverted_pendulum(){
    this->theta_pendulum=THETA_PENDULUM0;
    this->dtheta_pendulum=DTHETA_PENDULUM0;
}

inverted_pendulum::~inverted_pendulum(){
}

double inverted_pendulum::Get_theta(){
    return this->theta_pendulum;
}

double inverted_pendulum::Get_dtheta(){
    return this->dtheta_pendulum;
}

Eigen::Vector2d inverted_pendulum::Get_state(){
    Eigen::Vector2d state;
    state(0)=this->theta_pendulum;
    state(1)=this->dtheta_pendulum;
    return state;
}

void inverted_pendulum::Set_theta(double& theta){
    this->theta_pendulum=theta;    
}

void inverted_pendulum::Set_dtheta(double& dtheta){
    this->dtheta_pendulum=dtheta;
}

void inverted_pendulum::Set_state(Eigen::Vector2d& state){
    Set_theta(state(0));
    Set_dtheta(state(1));
}

inverted_pendulum InvPend;

Eigen::Vector2d f(Eigen::Vector2d state){
    Eigen::Vector2d ret;

    ret(0)=state(1);
    ret(1)=G/L*cos(state(0));
    return ret;
}

void RungeKutta(inverted_pendulum& ip ,double dt){
    Eigen::Vector2d org,var,s1,s2,s3,s4;
    org=ip.Get_state();
    var=ip.Get_state();

    s1=f(var);
    var=org+dt*s1/2.;

    s2=f(var);
    var=org+dt*s2/2.;

    s3=f(var);
    var=org+dt*s3;

    s4=f(var);

    org=org+dt*(s1+2*s2+2*s3+s4)/6;
    ip.Set_state(org);
}

void idle(void){
    glutPostRedisplay();
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //地面を描く
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-1.0, GROUND_HEIGHT-0.1);
    glVertex2d( 1.0, GROUND_HEIGHT-0.1);
    glVertex2d(-1.0, GROUND_HEIGHT);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d( 1.0, GROUND_HEIGHT);
    glVertex2d(-1.0, GROUND_HEIGHT);
    glVertex2d( 1.0, GROUND_HEIGHT-0.1);
    glEnd();

    //棒を描く
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-BAR_WIDTH/2*cos(InvPend.Get_theta()), GROUND_HEIGHT-BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glVertex2d( BAR_WIDTH/2*cos(InvPend.Get_theta()), GROUND_HEIGHT+BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glVertex2d(-BAR_WIDTH/2*cos(InvPend.Get_theta()), GROUND_HEIGHT+BAR_LENGTH-BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d( BAR_WIDTH/2*cos(InvPend.Get_theta()), GROUND_HEIGHT+BAR_LENGTH+BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glVertex2d(-BAR_WIDTH/2*cos(InvPend.Get_theta()), GROUND_HEIGHT+BAR_LENGTH-BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glVertex2d( BAR_WIDTH/2*cos(InvPend.Get_theta()), GROUND_HEIGHT+BAR_WIDTH/2*sin(InvPend.Get_theta()));
    glEnd();

    //円を描く
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for(int i=0;i<PART;i++){
        double rate=(double)i/PART;
        double x= RADIUS*cos(2.0*M_PI*rate);
        double y= RADIUS*sin(2.0*M_PI*rate);
        glVertex3d(x+BAR_LENGTH*sin(InvPend.Get_theta()), y+GROUND_HEIGHT+BAR_LENGTH*cos(InvPend.Get_theta()), 0.0);
    }
    glEnd();

    glutSwapBuffers();
    //   glFlush();

    RungeKutta(InvPend,DT);
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