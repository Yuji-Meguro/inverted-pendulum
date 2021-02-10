#include"define.hpp"
// #include"inverted-pendulum.hpp"
#include"simulation.hpp"
#include"graphics.hpp"
#include"pole-assignment.hpp"
// #include"equation-state.hpp"

#include<iostream>

pole_assignment InvPend;

int main(int argc,char *argv[]){
    // std::cout<< InvPend.Get_T()<<std::endl;
    // std::cout<< InvPend.Get_A_bar()<<std::endl;
    // std::cout<< InvPend.Get_B_bar()<<std::endl;
    graphics(argc, argv);
    return 0;
}