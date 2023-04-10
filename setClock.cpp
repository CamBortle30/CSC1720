/*
Cam Bortle
CSC1720
February 11th, 2020
/home/students/cbortle/csc1720/lab5/bortleLab5.cpp
Clock/Time Lab
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

  //Import Class
  class clockType
   { //Class Functions
   public:
      void setTime(int, int, int);
      void getTime(int&, int&, int&) const;
      void printTime() const;
      void incrementSeconds();
      void incrementMinutes();
      void incrementHours();
      bool equalTime(const clockType&) const;
   private://Private Variables
      int hr;
      int min;
      int sec;
   };

   //Declare Objects
   clockType myClock;
   clockType yourClock;

   int main()
   {
      //Initialize Variables
      int x, y, z, hours, minutes, seconds;
      x = 4;
      y = 33;
      z = 55;
      //Printing Clock In Different Ways 
      myClock.setTime(3, 48, 52);
      cout << "Setting My Clock" <<endl;
      myClock.printTime();
      cout << endl;
      myClock.setTime(x, y, z);
      cout << "Setting My Clock Using Variables" << endl;
      myClock.printTime();
      cout << endl;
      myClock.incrementSeconds();
      cout << "Print Clock After Incrementing Seconds" << endl;
      myClock.printTime();
      cout << endl;
      myClock.incrementMinutes();
      cout << "Print Clock After Incrementing Mintues" << endl;
      myClock.printTime();
      cout << endl;
      myClock.incrementHours();
      cout << "Print Clock After Incrementing Hours" << endl;
      myClock.printTime();
      cout << endl;
      myClock.equalTime(yourClock);
      cout << "Print Clock After Making Time Equal" << endl;
      myClock.printTime();
      cout << endl;

      cout << "Clock With All Intervals Over 100";
      cout << endl;
      myClock.setTime(148, 111, 120);
      myClock.printTime();
      cout <<endl;


      cout << "Enter Hours, Minutes, and Seconds" << endl;
      cin >> hours >> minutes >> seconds;
      cout << endl;
      myClock.setTime(hours, minutes, seconds);
      cout << endl;
      cout << "Clock Set Via User Input" << endl;
      myClock.printTime();
      cout << endl;


      yourClock.setTime(4, 47, 11);
      cout << "Setting Your Clock" << endl;
      yourClock.printTime();


   }

   //Get the time so you can do things with it
   void clockType::getTime(int& hours, int& minutes, int& seconds) const
   {
      hours = hr;
      minutes = min;
      seconds = sec;
   }

   //Function to print the time
   void clockType::printTime() const
   {
      if (hr<10)
         cout << "0";
      cout << hr << ":";
      if (min < 10)
         cout << "0";
      cout << min << ":";
      if (sec < 10)
         cout << "0";
      cout << sec;
   }
   //Function To increment the hours
   void clockType::incrementHours()
   {
      hr++;
      if (hr > 23)
         hr = 0;
   }
   //Function to increment the minutes
   void clockType::incrementMinutes()
   {
      min++;
      if (min > 59)
      {
         min = 0;
         incrementHours();
      }
   }

   //Function to increment the seconds
   void clockType::incrementSeconds()
   {
      sec++;

      if (sec > 59)
      {
         sec = 0;
         incrementMinutes();
      }

   }
   //Function to set clocks equal
   bool clockType::equalTime(const clockType& otherClock) const
   {
      return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
   }


   //Function to set the time of a given clock
   void clockType::setTime(int hours, int minutes, int seconds)
   {
      if (0 <= hours && hours < 24)
          hr = hours;
      else
          hr = 0;
      if (0 <= minutes && minutes < 60)
          min = minutes;
      else
          min = 0;
      if (0 <= seconds && seconds < 60)
          sec = seconds;
      else
          sec = 0;
   }
