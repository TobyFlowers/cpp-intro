#pragma once
#include <cmath>
#include "point.hpp"

class Line{

  public:
  Point p1 = Point(0,0);
  Point p2 = Point(0,0);
    Line(double x1, double y1, double x2, double y2);

  double length();


  double distance_to_point(Point p);

};