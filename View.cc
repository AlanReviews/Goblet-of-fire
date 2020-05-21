#include "View.h"

void View::displayMenu(int& choice)
{
  cout << "Welcome to the Goblet of Fire"<< endl;
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
