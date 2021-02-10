#pragma once
#include<Eigen/Dense>

class equation_state: public inverted_pendulum {
    protected:
        Eigen::Matrix2d A;
        Eigen::Vector2d B;
        Eigen::Vector2d K;
        Eigen::Matrix2d A_bar;
        Eigen::Vector2d B_bar;
        Eigen::Matrix2d T;
        double u;
    public:
        equation_state();
        ~equation_state();
        Eigen::Matrix2d Get_A();
        Eigen::Vector2d Get_B();
        Eigen::Vector2d Get_K();
        Eigen::Matrix2d Get_A_bar();
        Eigen::Vector2d Get_B_bar();
        Eigen::Matrix2d Get_T();
        double Get_u();
};