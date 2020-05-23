#include "Control.h"
#include "View.h"

#include <vector>

Control::Control() {

}

Control::~Control() {
    
}
void Control::launch(void) {
    View view;
    int choice;
    int age;
    string name;
    string school;
    vector<Participant> participants;

    while (1) {
        view.displayMenu(choice);
        if (choice == 0) {
            break;
        }
        // Add a participant to the Goblet of fire
        else if (choice == 1) {
            cout << "You are at the age line. Please enter your age:" << endl;
            cin >> age;
            if (age < 17) {
                cout << "You are not allowed to participate in the Triwizard Tournament." << endl;
                continue;
            }
            cout << "Please enter your name:" << endl;
            cin >> name;
            cout << "Please enter your school:" << endl;
            cin >> school;
            Participant p = Participant(name, age, school);
            participants.push_back(p);
        }
        else if (choice == 2) {
            
        }
    }

}