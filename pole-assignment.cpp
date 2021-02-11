#include"define.hpp"
#include"pole-assignment.hpp"
#include<iostream>

pole_assignment::pole_assignment(){    
    this->Pole=std::complex<double>(POLE_REAL,POLE_IMG);

    //極からゲインを求める
    this->K(0)=100.0;this->K(1)=10.0;
}

pole_assignment::~pole_assignment(){
}

std::complex<double> pole_assignment::Get_Pole(){
    return this->Pole;
}

Eigen::Vector2d pole_assignment::Get_K(){
    return this->K;
}
