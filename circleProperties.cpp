/*
Cam Bortle
CSC1720
January 28th, 2020
/home/students/cbortle/csc1720/lab3/bortleLab3.cpp
Find Radius Of Circle
*/


#include <iostream>
#include <cmath>
using namespace std;
//Declare Pi as a global constant since it will never change
const double PI = 3.1416;
//Function Prototypes; Telling Your Machine That These Functios Will Be Used
double distance(double point1x, double point1y, double point2x, double point2y);
double radius(double newX1, double newY1, double newX2, double newY2);
double circumference(double realRadius);
double area(double realRadius);
void printResults(double realRadius);


//Calculate Distance Between 2 Points
//Passing Parameters
double distance(double x1, double y1, double x2, double y2)
{
   double beforeSqrt, afterSqrt;
   //Use Of <cmath> functions pow and sqrt
   beforeSqrt = pow((x2 - x1), 2) + pow((y2 - y1), 2);
   afterSqrt = sqrt(beforeSqrt);

   cout << "The Distance Between Points 1 and 2 Is " << afterSqrt << endl;

   return afterSqrt;

}

//Calculate The Radius, Which is The Same Thing As The Distance
double radius(double newX1, double newY1, double newX2, double newY2)
{
   return distance(newX1,newY1,newX2,newY2);
}


//Calcuate The circumference by doubling the radius and multiplying it with Pi
double circumference(double realRadius)
{
   return realRadius * 2 * PI;
}

//Calculate The Area by Squaring the Radius and Multiplying it with Pi
double area(double realRadius)
{
   return pow(realRadius,2) * PI;
}

//This Function Outputs To The Console The Data From Your Previous Functions
void printResults(double realRadius)
{
   cout << "The Radius Of The Circle Is " << realRadius << endl;
   cout << "The Distance Of The Circle Is " << realRadius * 2 << endl;
   cout << "The Circumference Of The Circle Is " << circumference(realRadius) << endl;
   cout << "The Area Of The Circle Is " << area(realRadius) << endl;

}


int main()
{
   //Declaring Variables
   double point1x;
   double point1y;
   double point2x;
   double point2y;
   double realRadius;

   //User Input Prompt
   cout << "Enter The X Value For The First Point" << endl;
   cin >> point1x;
   cout << "Enter The Y Value For The First Point" << endl;
   cin >> point1y;
   cout << "Enter The X Value For The Second Point" << endl;
   cin >> point2x;
   cout << "Enter The Y Value For The Second Point" << endl;
   cin >> point2y;


   cout << "Point 1 Is ("<< point1x << "," << point1y << ")" << endl;
   cout << "Point 2 Is ("<< point2x << "," << point2y << ")" << endl;


   //realDistance = distance(point1x, point1y, point2x, point2y);
   //Functiion Call
   realRadius = radius(point1x, point1y, point2x, point2y);
   printResults(realRadius);

   return 0;
}