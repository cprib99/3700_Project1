//Cam Pribulsky
//Created 4 Feb 2020
#include <iostream>
#include <fstream>
#include "fraction.h"
#include "point.h"
using namespace std;

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

    cout << testPoint << "Test" << endl;;


    return 0;
}
