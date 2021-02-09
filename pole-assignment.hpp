#pragma once
#include"inverted-pendulum.hpp"
#include"equation-state.hpp"
#include<Eigen/Dense>
#include<complex>

class pole_assignment : public equation_state{
    protected:
        Eigen::Vector2d Gain;
        std::complex<double> Pole;
    public:
        pole_assignment();
        ~pole_assignment();
        Eigen::Vector2d Get_Gain();
        std::complex<double> Get_Pole();
};