#include "View.h"

// THe displayMenu function to print out a user interface to the terminal
void View::displayMenu(int& choice)
{
  cout << "Welcome to the Goblet of Fire"<< endl;
  cout << "Remember, when you enter your name, you must participate in the Triwizard Tournament otherwise your magic will be gone" << endl;
  cout << "  1. Enter a participant:" << endl;
  cout << "  2. Draw out:" << endl;
  cout << "  0. Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > 2) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}
