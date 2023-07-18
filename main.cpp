#include <iostream>
#include <cmath>
#include <vector>

int main()
{
  std::cout << "Hello, world!" << std::endl;

  int x = 5;
  int y = 7;
  std::cout << "The sum of " << x << " and " << y << " is " << x + y << std::endl;
  std::string name = "Toby";
  std::string cname = "AUVC";
  std::cout << "My name is " << name << " and" << " my class is " << cname << std::endl;

  int z = 10;
  std::cout << "The sum of " << x << ", " << y << ", and " << z << " is " << x + y + z << std::endl;

  int w = 2;
  std::cout << "The product of " << x << ", " << y << ", " << z << "and " << w << " is " << x * y * z * w << std::endl;

  int v = 1;
  std::cout << "The result of the division of " << x << ", " << y << " and " << v << " is " << (x/y)/v << std::endl;




  return 0;
}

int subtract(int x, int y){
  return (x-y);
}

int multiply(int x, int y){
  return (x*y);
}

int divide(int x, int y){
  return (x/y);
}

class Circle
{
public:
  Circle(double r)
  {
    this->radius = 4;
  }
  
  double radius;
  double area()
  {
    return M_PI * pow(radius, 2);
  }
};

class Point{

  public:
  double x = 0;
  double y = 0;
    Point(double x, double y){
      this->x = x;
      this->y = y;
    }

  double distance_to_origin()
  {
    return sqrt(pow(x,2) + pow(y,2));
  }

  double distance_to_point(Point p)
  {
      return sqrt(pow((x - p.x),2) + pow((y- p.y),2));
  }

  double distance_to_line(Line line) {
    double dy = line.p2.y - line.p1.y;
    double dx = line.p2.x - line.p1.x;
    double c = dy * line.p1.x + dx * line.p1.y;

    double distance = std::abs(dy * x + dx * y - c) / std::sqrt(dy * dy + dx * dx);
    return distance;
}

};

class Line{

  public:
  Point p1 = Point(0,0);
  Point p2 = Point(0,0);
    Line(double x1, double y1, double x2, double y2){
      p1 = Point(x1, y1);
      p2 = Point(x2, y2);
    }

  double length()
  {
    return sqrt(pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2));
  }


  double distance_to_point(Point p) {
    double dy = p2.y - p1.y;
    double dx = p2.x - p1.x;
    double c = dy * p1.x + dx * p1.y;

    double distance = abs(dy * p.x + dx * p.y - c) / sqrt(dy * dy + dx * dx);
    return distance;
  }

};


class Triangle{
  public:
  Point p1 = Point(0,0);
  Point p2 = Point(0,0);
  Point p3 = Point(0,0);
  Triangle(Point p1, Point p2, Point p3)
  {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
  }

  double area()
  {
    double a = p1.distance_to_point(p2);
    double b = p1.distance_to_point(p3);
    double dist_p2_p3 = p2.distance_to_point(p3);
    double c = acos((pow(dist_p2_p3,2) - pow(a,2)- pow(b,2))/2*a*b);
    return (0.5 * a * b * sin(c));
  }

};

class Polygon {
public:
  std::vector<Point> vertices;

  Polygon(const std::vector<Point> points) {
    vertices = points;
  }

  double area()
  {
    double area = 0;
    for(int i = 1; i < vertices.size()-1; i++)
    {
        Triangle temp_t(vertices[0], vertices[i], vertices[i+1]);
        area += temp_t.area();
    }

    return area;
  }

  double perimeter(){
    double perimeter = 0;
    for(int i = 0; i < vertices.size()-1; i++)
    {
        perimeter+=vertices[i].distance_to_point(vertices[i+1]);
    }

    return perimeter;
    
  }
};



