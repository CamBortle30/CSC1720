/*
Cam Bortle
CSC1720
April 13th, 2020
/home/students/cbortle/csc1720/programs/program3/bortleProgram3.cpp
Recursive Function Program
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
//Repower  Function
int Repower(int j, int k)
{
   if(k != 0)
   {
     return (j * Repower(j, k-1));
   }
   else
   {
      return 1;
   }
}
int main()
{
   //Declare Variables
   int base, exp, result;
   char answer;
   //Prompt to run
   cout << "Would You Like To Run? y/n?  " << endl;
   cin >> answer;
   //Master While Loop
   while (answer != 'n')
   {
      //Enter in Base Number, no larger than 100 serves as overflow warning
      cout << "Please Enter A Positive Integer As A Base Number (No Larger Than 100): " << endl;
      cin >> base;
      //Validation for Base being positive
      if(base < 0)
      {
         cout <<"Please Enter A Positive Integer (No Larger Than 100): " << endl;
         cin >> base;
      }
      //Enter Exponent number, no larger than 20 serves as overflow warning
      cout << "Please Enter Exponent Number (No Larger Than 20): " << endl;
      cin >> exp;
      //Call Repower Function
      result = Repower(base, exp);
      cout << "The Result Is: " << result << endl;
      //Prompt to run program again
      cout << "Would You Like To Run The Program Again? y/n? " << endl;
      cin >> answer;

   }
   return 0;
}