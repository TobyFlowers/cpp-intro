#include "line.hpp"
Line::Line(double x1, double y1, double x2, double y2){
      p1 = Point(x1, y1);
      p2 = Point(x2, y2);
    }

double Line::length()
  {
    return sqrt(pow((p2.x()-p1.x()),2) + pow((p2.y()-p1.y()),2));
  }

  double Line::distance_to_point(Point p){
    double dy = p2.y() - p1.y();
    double dx = p2.x() - p1.x();
    double c = dy * p1.x() + dx * p1.y();

    double distance = abs(dy * p.x() + dx * p.y() - c) / sqrt(dy * dy + dx * dx);
    return distance;
  }