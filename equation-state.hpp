#pragma once
#include<Eigen/Dense>

class equation_state: public inverted_pendulum {
    protected:
        Eigen::Matrix2d A;
        Eigen::Vector2d B;
        double u;
    public:
        equation_state();
        ~equation_state();
        Eigen::Matrix2d Get_A();
        Eigen::Vector2d Get_B();
        double Get_u();
};