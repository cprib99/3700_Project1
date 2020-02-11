//Cam Pribulsky
//Created 4 Feb 2020
#include <iostream>
#include <fstream>
#include "fraction.h"
#include "point.h"
using namespace std;

//global variable numPoints - used in fcn definitions to know how many points to iterate for
int numPoints;
//global var fraction1 for converting values to fractions
Fraction fraction1 = (1,1);
Fraction fraction0 = (0,0);

//Algorithm 1 - find point outside of polygon Q
Point findOustidePoint(Point Q[], Point p1)
{
  //get yMax point
  Fraction yTemp;

  for(int i=0; i<numPoints; i++)
  {
    if(Q[i].getY().operator>=(yTemp))
    {
      yTemp = Q[i].getY();
    }
  }

  Fraction x;
  yTemp.operator=(yTemp.operator+(fraction1));

  cout << yTemp << endl;

  Point p2(x,yTemp);
  bool good = false;

  //loop for finding yMax
  while(good = false)
  {
    x = x + fraction1;
    good = true;
    for (int i=0; i<(numPoints-1); i++)
    {
      if(((Q[i].operator-(p1)).operator*(p2.operator-(p1)) == 0))
      {
        good = false;
      }
    }
  }
  return(x,yTemp);
}

bool intersect(Point p1, Point p2, Point q1, Point q2)
{
  Point r, s, v;
  Fraction d, t, u, vs, vr;
  r = p2.operator-(p1);
  s = q2.operator-(q1);
  v = q1.operator-(p1);
  d = r.operator*(s);

  if(d.operator==(fraction0))
  {
    return false;
  }
  else
  {
    vs.operator=(v.operator*(s));
    vr.operator=(v.operator*(r));
    t.operator=(vs.operator/(d));
    u.operator=(vr.operator/(d));
    if(((t.operator>=(fraction0) && t.operator<=(fraction1)) && ((u.operator>=(fraction0) && (u.operator>=(fraction1))))
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

//test section below
    //cout << testPoint << endl;;

    Point outsidePoint;
    outsidePoint = findOustidePoint(pointData, testPoint);
    cout << outsidePoint << endl;



    return 0;
}
