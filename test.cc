//Cam Pribulsky
//Created 4 Feb 2020
#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

//prototype for function to pull ints from strings
void separateString(string equ, vector<int> &digits)
{
    for (auto i : equ)
    {
        if (isdigit(i))
          {
            digits.push_back(stoi(string{i}));
        }
    }

}

//test1
//main function to read strings from file and place in usable vector
int main()
{
    int numPoints, count;
    string str, testPt;
    vector<string> pointVec;
    bool firstNum;
    ifstream inFile;
    firstNum = true;

    inFile.open("test1.dat"); //place external file into inFile

    //read string from file and place into vector
    while(inFile >>str)
    {
        if(firstNum)    //Puts first into numPoints
        {
            firstNum = false;
            numPoints = atoi(str.c_str());   //string to int conversion
        }
        else
        {
            pointVec.push_back(str);    //add point to vector
            count++;
        }
    }

    //set up test points
    testPt=pointVec[numPoints]; //get test point (last one) from vector
    pointVec.pop_back();  //erase test point from vector

    //list points in vector
    for(int i=0; i<pointVec.size(); i++)
    {
      cout<<pointVec[i]<<endl;
    }

    //output everything read from the file, but in the good format
    cout<<numPoints<<endl;
    cout<<testPt<<endl;

    //separate integers from vector of strings
    int j=0;
    vector<int> digits;
    separateString(pointVec[j], digits);
    j++;

    vector<int> digits1;
    separateString(pointVec[j], digits1);
    j++;

    vector<int> digits2;
    separateString(pointVec[j], digits2);
    j++;

    vector<int> digits3;
    separateString(pointVec[j], digits3);

    //section for checking int vectors
/*
    cout << endl;
    for (auto& i : digits)
    {
       cout << i << " ";

     }
      cout << endl;
*/

    //close down
    inFile.close();
    return 0;
};
