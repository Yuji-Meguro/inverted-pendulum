#include"simulation.hpp"
#include"define.hpp"
#include<iostream>

Eigen::Vector2d f(pole_assignment &ip){
    Eigen::Vector2d ret;
    Eigen::Vector2d force;
    force=(ip.Get_B()*ip.Get_K().transpose()*ip.Get_state());
    std::cout<< force<<std::endl;

    ret(0)=ip.Get_dtheta()-force(0);
    ret(1)=GACCE/LENGTH*sin(ip.Get_theta())-force(1);
    return ret;
}

void RungeKutta(pole_assignment& ip,double dt){
    pole_assignment var;
    Eigen::Vector2d org,s1,s2,s3,s4,ref;
    
    var=ip;
    org=ip.Get_state();

    s1=f(var);
    ref=org+dt*s1/2.;
    var.Set_state(ref);

    s2=f(var);
    ref=org+dt*s2/2.;
    var.Set_state(ref);

    s3=f(var);
    ref=org+dt*s3;
    var.Set_state(ref);

    s4=f(var);

    org=org+dt*(s1+2*s2+2*s3+s4)/6.0;

    if(org(0)>M_PI){org(0)-=2*M_PI;}
    else if(org(0)<-M_PI){org(0)+=2*M_PI;}

    ip.Set_state(org);
}
