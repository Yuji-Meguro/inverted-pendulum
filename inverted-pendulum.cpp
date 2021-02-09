#include"inverted-pendulum.hpp"
#include"define.hpp"

inverted_pendulum::inverted_pendulum(){
    this->theta_pendulum=THETA_PENDULUM0;
    this->dtheta_pendulum=DTHETA_PENDULUM0;

    this->A(0,0)=0.;this->A(0,1)=1.;
    this->A(1,0)=GACCE/LENGTH;this->A(1,1)=0.;
    this->B(0)=0.;this->B(1)=1.;
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

Eigen::Matrix2d inverted_pendulum::Get_A(){
    return this->A;
}

Eigen::Vector2d inverted_pendulum::Get_B(){
    return this->B;
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
