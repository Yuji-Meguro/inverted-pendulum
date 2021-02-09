#pragma once
#include<Eigen/Dense>

class inverted_pendulum{
    protected:
        //パラメータ
        double theta_pendulum;//角度
        double dtheta_pendulum;//角速度
    public:
        inverted_pendulum();
        ~inverted_pendulum();
        double Get_theta();
        double Get_dtheta();
        Eigen::Vector2d Get_state();
        void Set_theta(double&);
        void Set_dtheta(double&);
        void Set_state(Eigen::Vector2d&);
};
