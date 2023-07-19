#include "polygon.hpp"

std::vector<Point> vertices;

Polygon::Polygon(const std::vector<Point> points) {
    vertices = points;
  }


double Polygon::area()
  {
    double area = 0;
    for(int i = 1; i < vertices.size()-1; i++)
    {
        Triangle temp_t(vertices[0], vertices[i], vertices[i+1]);
        area += temp_t.area();
    }

    return area;
  }

  double Polygon::perimeter()
  {
    
    double perimeter = 0;
    for(int i = 0; i < vertices.size()-1; i++)
    {
        perimeter+=vertices[i].distance_to_point(vertices[i+1]);
    }

    return perimeter + vertices[vertices.size() -1].distance_to_point(vertices[0]);
    
  }