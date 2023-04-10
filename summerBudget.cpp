/*
Cam Bortle
CSC 1720
January 14th, 2020
Lab 1
/home/students/cbortle/csc1720/lab1/bortleHello.cpp
Program to serve as a budget manager for working a summer job, calculates spending of X amount of money on certain things 
*/
#include <iostream>
using namespace std;

int main()

{
   //Initialize Pay rate, hours worked, and how much money you made variables
   double pay;
   int hoursWorked, i, sumOfHours=0;
   double moneyMade;
   int weekNumber = 0;

   //Hello World Print Statement
   cout << "Hello World!"<<endl;


   //Hourly Rate User Prompt
   cout <<"How Much Are You Paid Per Hour at Your Summer Job?: "<<endl;
   cin >> pay;
   //Hours Worked per Week For Loop
   for(i=0; i<5; i++)
   {
   weekNumber += 1;
   cout <<"How Many Hours Did You Work This Week #" << weekNumber <<endl;
   cin >> hoursWorked;
   sumOfHours = hoursWorked + sumOfHours;
   }

  cout <<"You Worked "<<sumOfHours<<" Hours This Summer"<<endl;


   //Amount Of Money Remaining Equations
   moneyMade = pay * sumOfHours;
   double afterTax = moneyMade * .14;
   double totalAfterTax = moneyMade - afterTax;
   double afterClothes = afterTax * .10;
   double afterSupplies = afterClothes * .01;
   double afterBonds = afterSupplies * .25;

   //How Much Money Was Spent Equations
   double taxAmount = moneyMade -(moneyMade * .07);
   double clothesAmount = afterTax - afterTax * .10;
   double suppliesAmount = afterClothes - afterClothes * .01;
   double bondAmount = afterSupplies - afterSupplies * .25;

   //Print Statements
   cout <<"You Made $"<<moneyMade<<endl;
   cout <<"You Lost $"<<afterTax<<" From Taxes"<<endl;
   cout <<"After Taxes, You Have $"<<totalAfterTax<<endl;
   cout <<"You Spent $"<<clothesAmount<<" Buying Clothes and Other Accesories For The School Year"<<endl;
   cout <<"After Buying Clothes and Other Accesories For The School Year, You Have $"<<afterClothes<<endl;
   cout <<"You Spent $"<<suppliesAmount<<" Buying School Supplies"<<endl;
   cout <<"After Buying School Supplies, You Have $"<<afterSupplies<<endl;
   cout <<"You Spent $"<<bondAmount<<" Buying Savings Bonds"<<endl;
   cout <<"After Buying Savings Bonds, You Have $"<<afterBonds<<endl;


   return 0;
}