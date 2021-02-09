#pragma once
#include"pole-assignment.hpp"

extern pole_assignment InvPend;

#define GROUND_HEIGHT 0.0//地面の高さ
#define PART 50//円の分割数
#define RADIUS 0.1//円の半径
#define BAR_WIDTH 0.05//棒の幅
#define BAR_LENGTH 0.5//棒の長さ

#define GACCE 9.81//重力加速度
#define DT 0.01//刻み時間

#define MASS 1.0
#define LENGTH 1.0

#define THETA_PENDULUM0 2.0
#define DTHETA_PENDULUM0 1.0

#define POLE_REAL   (-5.)
#define POLE_IMG    2.