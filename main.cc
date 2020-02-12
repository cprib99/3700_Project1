//Cam Pribulsky
//Created 4 Feb 2020
#include <iostream>
#include <fstream>
#include "fraction.h"
#include "point.h"
using namespace std;

//Algorithm 1 - find point outside of polygon Q
Point findOustidePoint(Point *Q, Point p1, int pointNums)
{
  //get yMax point
  Fraction yTemp;

  for(int i=0; i<pointNums; i++)
  {
    if(Q[i].getY()>=(yTemp))
    {
      yTemp = Q[i].getY();
    }
  }

  //create point p2
  Fraction x;
  yTemp = yTemp + 1;
  Point p2(x,yTemp);

  //loop for finding yMax
  bool good;
  do
  {
    x = x + 1;
    good = true;
    for (int i=0; i<(pointNums-1); i++)
    {
      if((Q[i]-p1)*(p2-p1) == 0)
      {
        good = false;
      }
    }
  } while(good = false);
  return(x,yTemp);
}

//Algorithm 2 - determine if two line segments intersect
bool intersect(Point p1, Point p2, Point q1, Point q2)
{
  Point r, s, v;
  Fraction d, t, u, vs, vr;
  r = p2 - p1;
  s = q2 - q1;
  v = q1 - p1;
  d = r * s;

  if(d == 0)
  {
    return false;
  }
  else
  {
    vs = v * s;
    vr = v * r;
    t = vs / d;
    u = vr / d;
    if((t>=0) && (t<=1) && (u>=0) && (u<=1))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

int main()
{
    //open file in program
    ifstream inFile;
    inFile.open("test1.dat");

    //initialize file and create vector to get points
    int numPoints;
    inFile >>numPoints;
    Point pointData[(numPoints+1)], testPoint;

    //read points from file
    for(int i=0; i<numPoints+1; i++)
    {
      inFile>>pointData[i];
    }
    testPoint = pointData[numPoints];

    //find known point outside of polygon
    Point outsidePoint;
    outsidePoint = findOustidePoint(pointData, testPoint, numPoints);

    //determine number of collisions of line segments
    int numCollisions;
    for(int i=1; i<numPoints; i++)
    {
      if(intersect(testPoint, outsidePoint, pointData[i-1],pointData[i]))
      {
        numCollisions++;
      }
    }

    //finally - check if point is inside of polygon!
    //use definition of even/odd number here
    if(numCollisions % 2 == 0)
    {
      cout << "Point is outside the polygon" << endl;
    }
    else
    {
      cout << "Point is inside the polygon" << endl;
    }

    return 0;
}
