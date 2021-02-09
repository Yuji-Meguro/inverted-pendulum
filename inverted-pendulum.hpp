#pragma once
#include<Eigen/Dense>

class inverted_pendulum{
    protected:
        //パラメータ
        double theta_pendulum;//角度
        double dtheta_pendulum;//角速度

        Eigen::Matrix2d A;//状態方程式
        Eigen::Vector2d B;//状態方程式
        Eigen::Vector2d K;//フィードバックゲイン
    public:
        inverted_pendulum();
        ~inverted_pendulum();
        double Get_theta();
        double Get_dtheta();
        Eigen::Vector2d Get_state();
        Eigen::Matrix2d Get_A();
        Eigen::Vector2d Get_B();
        void Set_theta(double&);
        void Set_dtheta(double&);
        void Set_state(Eigen::Vector2d&);
};
