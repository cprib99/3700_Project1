//Cam Pribulsky
//Created 4 Feb 2020

#include "point.h"
#include "fraction.h"


Point::Point(Fraction x, Fraction y)
{
  this->x = x;
  this->y = y;
}

Point Point::operator+(Point rhs)
{
  Fraction xNew,yNew;
  xNew = x + rhs.x;
  yNew = y + rhs.y;
  return Point(xNew,yNew);
}

Point Point::operator-(Point rhs)
{
  Fraction xNew,yNew;
  xNew = x - rhs.x;
  yNew = y - rhs.y;
  return Point(xNew,yNew);
}

Point Point::operator*(Fraction rhs)
{
  Fraction xNew,yNew;
  xNew = x * rhs;
  yNew = y * rhs;
  return Point(xNew,yNew);
}

Fraction Point::operator*(Point rhs)
{
  return ((x*rhs.y)-(y*rhs.x));
}

bool Point::operator==(Point rhs)
{
  return x == rhs.x && y == rhs.y;
}

bool Point::operator!=(Point rhs)
{
  return x != rhs.x || y != rhs.y;
}

std::istream &operator>>(std::istream &is, Point &p)
{
  Fraction
  a,b;
  char lp, comma, rp;

  is >> lp >> a >> comma >> b >> rp;
  p=Point(a,b);
  return is;
}

std::ostream &operator<<(std::ostream &os, Point f)
{
  os << "(" << f.getX() << "," << f.getY() << ")";
  return os;
}
