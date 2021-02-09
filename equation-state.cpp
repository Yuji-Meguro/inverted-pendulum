#include"define.hpp"
#include"equation-state.hpp"

equation_state::equation_state(){
    this->A(0,0)=0;this->A(0,1)=1;
    this->A(1,0)=GACCE/LENGTH;this->A(1,1)=0;

    this->B(0)=0.;this->B(1)=1.;

    u=0.;
}

equation_state::~equation_state(){

}

Eigen::Matrix2d equation_state::Get_A(){
    return this->A;
}

Eigen::Vector2d equation_state::Get_B(){
    return this->B;
}