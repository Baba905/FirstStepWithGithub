#include <iostream>
#include<string>
#include "Robot.h"


using namespace std;

Robot::Robot():name("first"), type("primitive"), price(0){}

Robot::Robot( string nom, string  type, double prix): name(nom),type(type), price(prix){}

string Robot::getName()const{
    return name;
}

bool Robot::operator<(const Robot & other)const{
    return price < other.price;
}

ostream & operator<<(std::ostream & out, const Robot & p){
    out<<p.name<<"|"<<p.type<<"|"<<p.price<<";"<<endl;
    return out;
}

istream & operator>>(istream & in, Robot & p){
    in>>p.name>>p.type>>p.price;
    return in;
}