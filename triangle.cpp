#include "triangle.hpp"

  Triangle::Triangle(Point p1, Point p2, Point p3)
  {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
  }

double Triangle::area(){

    double a = p1.distance_to_point(p2);
    double b = p1.distance_to_point(p3);
    double dist_p2_p3 = p2.distance_to_point(p3);
    double c = acos((pow(dist_p2_p3,2) - pow(a,2)- pow(b,2))/2*a*b);
    return (0.5 * a * b * sin(c));
}
