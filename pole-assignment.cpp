#include"define.hpp"
#include"pole-assignment.hpp"
#include<iostream>

pole_assignment::pole_assignment(){    
    this->Pole=std::complex<double>(POLE_REAL,POLE_IMG);

    //極からゲインを求める
    // this->K(0)=K1;this->K(1)=K2;
    this->K(0)=-2*POLE_REAL/this->B(1);
    this->K(1)=-(-(POLE_REAL*POLE_REAL+POLE_IMG*POLE_IMG)/this->A(0,1) - this->A(1,0))/this->B(1);
}

pole_assignment::~pole_assignment(){
}

std::complex<double> pole_assignment::Get_Pole(){
    return this->Pole;
}

Eigen::Vector2d pole_assignment::Get_K(){
    return this->K;
}
