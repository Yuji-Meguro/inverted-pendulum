#include"define.hpp"
#include"pole-assignment.hpp"
#include<iostream>

pole_assignment::pole_assignment(){    
    this->Pole=std::complex<double>(POLE_REAL,POLE_IMG);
    // std::cout<< this->Pole <<std::endl;
}

pole_assignment::~pole_assignment(){
}

Eigen::Vector2d pole_assignment::Get_Gain(){
    return this->Gain;
}

std::complex<double> pole_assignment::Get_Pole(){
    return this->Pole;
}