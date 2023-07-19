#include "auv.hpp"

AUV::AUV(std::string name,
Point position,
double depth,
double heading,
std::array<double,3> speed,
double angular_speed){
  this->name = name;
  this->position = position;
  this->depth = depth;
  this->heading = heading;
  this->speed = speed;
  this->angular_speed = angular_speed;

}

void AUV::step(double dt)
{
  double x = position.x();
  double y = position.y();
  position.setx(x + speed[0]*dt); 
  position.sety(y + speed[1] * dt);
  depth += speed[2] * dt;      
}

void AUV::apply_acceleration(const std::array<double, 3> acceleration, double dt) {
  speed[0] += acceleration[0] * dt;  
  speed[1] += acceleration[1] * dt; 
  speed[2] += acceleration[2] * dt;  
}

void AUV::apply_angular_acceleration(double angular_acceleration, double dt) {
    angular_speed += angular_acceleration * dt;
    heading += angular_speed * dt;
  }