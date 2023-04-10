
/*
Cam Bortle
CSC1720
April 27th, 2020
/home/students/cbortle/csc1720/programs/program4/bortleProgram4.cpp
Card Suit/Value Guessing Game
*/
//Including STL, Vector Functions, and Algorithm Functions
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
//Base Class Header
class Card
{

   public:
      string getValues();
      string getSuit();
      Card(int value, int suit);
      Card();
   private:
      int cardValue;
      int cardSuit;
      static const char* const values[13];
      static const char* const suits[4];
};


//List of Face Values and Suits
   const char* const Card::values[]={"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

   const char* const Card::suits[]={"Clubs", "Diamonds", "Hearts", "Spades"};
//Default Constructor
Card::Card()
{
   cardValue = 0;
   cardSuit = 0;
}
//Parameterized Constructor
Card::Card(int value_Of_Card, int suit_Of_Card)
{
   cardValue = value_Of_Card;
   cardSuit = suit_Of_Card;
}
//Function to get Face Value
string Card::getValues()
{
   return values[cardValue];
}
//Function to get suit
string Card::getSuit()
{
   return suits[cardSuit];
}
//Derived Class Header
class DeckOfCards: public Card
{
//#include <vector>
   public:
      Card getRandomCard();
      void shuffle();
      DeckOfCards();
      void printCards();
   private:
      vector<Card> deck;
};
//Derived Class Default Constructor
DeckOfCards::DeckOfCards()
{
   deck.reserve(13 * 4);

   for(int i=0; i<13; i++)
   {
      for(int j=0; j<4; j++)
      {
         Card card(i,j);
         deck.push_back(card);
      }
   }
}
//Function to shuffle cards
void DeckOfCards::shuffle()
{
   srand(time(0));
   random_shuffle(deck.begin(), deck.end());
}
//Function to return a random card from shuffle()
Card DeckOfCards::getRandomCard()
{
   srand(time(0));
   int r = rand() % 13;
   return deck[r];
}

//Prints all potential cards 
void DeckOfCards::printCards()
{
   for(unsigned int i=0; i<deck.size(); i++)
   {
      cout << deck[i].getValues()<< " of " << deck[i].getSuit() << endl;
   }
}

int main()
{
   int choice = 0;
   string myFace;
   string mySuit;

   DeckOfCards myDeck;
   Card randomCard;
   //Print out all the cards
   cout << "Cards In The Deck" << endl;
   myDeck.printCards();

   do
   {
      //Give User Options as to what they want to do
      cout << "1. Guess The Face Value Of The Card" << endl;
      cout << "2. Guess The Suit Of The Card" << endl;
      cout << "3. Guess The Face Value and The Suit Of The Card" << endl;
      cout << "4. Exit" << endl;
      cout << "Enter Your Choice: " << endl;
      cin >> choice;
      if(choice == 1 || choice == 2 || choice == 3)
      {
         //Cards will always shuffle 
         myDeck.shuffle();
         randomCard = myDeck.getRandomCard();
      }
      switch(choice)
      {
         case 1: //Guessing only face value
            cout << "Enter the Face Value: ";
            cin >> myFace;
            if(myFace == randomCard.getValues())
            {
               cout << "Congrats! You have Guessed The Correct Face Value!" << endl;
            }
            else
            {
               cout << "Incorrect Face Value" << endl;
               cout << "The Correct Face Value Is: " << randomCard.getValues() << endl;
            }
            break;

            case 2: //Guessing only suite value
               cout << "Enter the Suite Value: " << endl;
               cin >> mySuit;
               if(mySuit == randomCard.getSuit())
               {
                  cout << "Congrats! You Have Guessed The Correct Suite Value";
               }
               else
               {
                  cout << "Incorrect Suite Value" << endl;
                  cout << "The correct Suite Value is " << randomCard.getSuit() << endl;
               }
            break;

            case 3: //Guess Face AND suite values
               cout << "Enter The Face Value: ";
               cin >> myFace;
               cout << "Enter The Suite Value: ";
               cin >> mySuit;
               if(myFace == randomCard.getValues() && mySuit == randomCard.getSuit())
               {
                  cout << "Congrats! You Have Guessed The Correct Card From The Deck." << endl;
               }
               else
               {
                  cout << "Incorrect Card Guess" << endl;
                  cout << "The Correct Card Is: " << randomCard.getValues() << "of" << randomCard.getSuit() << endl;
               }
             break;

             case 4: //Case to quit the game
                cout <<"Thank You!" << endl;
             break;
             default:
                cout << "Invalid Choice, Try Again." << endl;
          }
   }
   while(choice !=4);










     return 0;
}