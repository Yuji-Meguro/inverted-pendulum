#include"simulation.hpp"
#include"define.hpp"

Eigen::Vector2d f(Eigen::Vector2d state){
    Eigen::Vector2d ret;

    ret(0)=state(1);
    ret(1)=GACCE/LENGTH*sin(state(0));
    return ret;
}

void RungeKutta(pole_assignment& ip ,double dt){
    Eigen::Vector2d org,var,s1,s2,s3,s4;
    org=ip.Get_state();
    var=ip.Get_state();

    s1=f(var);
    var=org+dt*s1/2.;

    s2=f(var);
    var=org+dt*s2/2.;

    s3=f(var);
    var=org+dt*s3;

    s4=f(var);

    org=org+dt*(s1+2*s2+2*s3+s4)/6;
    if(org(0)>M_PI){
        org(0)-=2*M_PI;
    }
    else if(org(0)<-M_PI){
        org(0)+=2*M_PI;
    }

    ip.Set_state(org);
}
