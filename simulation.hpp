#pragma once
#include"pole-assignment.hpp"

Eigen::Vector2d f(Eigen::Vector2d);
void RungeKutta(pole_assignment& ,double );