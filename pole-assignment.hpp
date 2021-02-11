#pragma once
#include"inverted-pendulum.hpp"
#include"equation-state.hpp"
#include<Eigen/Dense>
#include<complex>

class pole_assignment : public equation_state{
    protected:
        std::complex<double> Pole;
        Eigen::Vector2d K;

    public:
        pole_assignment();
        ~pole_assignment();
        std::complex<double> Get_Pole();
        Eigen::Vector2d Get_K();
};