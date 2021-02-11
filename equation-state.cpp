#include"define.hpp"
#include"equation-state.hpp"
#include<iostream>

equation_state::equation_state(){
    this->A(0,0)=0;this->A(0,1)=1;
    this->A(1,0)=GACCE/LENGTH;this->A(1,1)=0;

    this->B(0)=0.;this->B(1)=1.;

    Eigen::SelfAdjointEigenSolver<Eigen::Matrix2d> eigensolver(this->A);
    if (eigensolver.info() != Eigen::Success) abort();
    this->T=eigensolver.eigenvectors();

    this->A_bar=this->T.inverse()*this->A*this->T;
    this->B_bar=this->T.inverse()*this->B;

    this->K(0)=100.0;this->K(1)=10.0;

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

Eigen::Vector2d equation_state::Get_K(){
    return this->K;
}

Eigen::Matrix2d equation_state::Get_A_bar(){
    return this->A_bar;
}

Eigen::Vector2d equation_state::Get_B_bar(){
    return this->B_bar;
}

Eigen::Matrix2d equation_state::Get_T(){
    return this->T;
}

double equation_state::Get_u(){
    return this->u;
}