#pragma once
#include"inverted-pendulum.hpp"

Eigen::Vector2d f(Eigen::Vector2d);
void RungeKutta(inverted_pendulum& ,double );