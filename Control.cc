#include "Control.h"
#include "View.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <limits>

Control::Control() {

}

Control::~Control() {
    
}

// Draw a participant from a selected school
void Control::drawParticipant(vector<Participant> candidates, string school) {
    int candidateNum = rand() % candidates.size();
    while (candidates[candidateNum].getSchool() != school) {
        candidateNum = rand() % candidates.size();
    }
    candidates[candidateNum].displayInfo();
}


void Control::launch(void) {
    // Initialize the random seed
    srand( (unsigned)time( NULL ) );
    View view;
    int choice;
    int age;
    char name[100] = {};
    string school;
    vector<Participant> participants;
    bool hasHogwarts = false;
    bool hasDurmstrang = false;
    bool hasBeauxbatons = false;

    while (1) {
        view.displayMenu(choice);
        if (choice == 0) {
            break;
        }
        // Add a participant to the Goblet of fire
        else if (choice == 1) {
            cout << "You are at the age line. Please enter your age:" << endl;
            cin >> age;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (age < 17) {
                cout << "You are not allowed to participate in the Triwizard Tournament." << endl;
                continue;
            }
            cout << "Please enter your name:" << endl;
            cin.getline(name, sizeof(name));
            cout << endl;
            cout << "Please enter your school:" << endl;
            cin >> school;
            if (school == "Hogwarts") {
                hasHogwarts = true;
            }
            else if (school == "Beauxbatons") {
                hasBeauxbatons = true;
            }
            else if (school == "Durmstrang") {
                hasDurmstrang = true;
            }
            Participant p = Participant(name, age, school);
            participants.push_back(p);
        }
        else if (choice == 2 && participants.size() >= 3 && (hasHogwarts && hasBeauxbatons && hasDurmstrang))  {
            drawParticipant(participants, "Hogwarts");
            drawParticipant(participants, "Beauxbatons");
            drawParticipant(participants, "Durmstrang");
        }
    }
}