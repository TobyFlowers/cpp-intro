#pragma once
#include <cmath>
#include "point.hpp"
#include <vector>
#include "triangle.hpp"

class Polygon {
public:
  std::vector<Point> vertices;

  Polygon(const std::vector<Point> points);

  double area();
  double perimeter();
};