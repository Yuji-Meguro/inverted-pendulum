#include"define.hpp"
#include"inverted-pendulum.hpp"

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
