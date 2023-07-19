#pragma once
#include <cmath>
#include "point.hpp"

class Triangle{
  public:
  Point p1 = Point(0,0);
  Point p2 = Point(0,0);
  Point p3 = Point(0,0);
  Triangle(Point p1, Point p2, Point p3);
  double area();
};