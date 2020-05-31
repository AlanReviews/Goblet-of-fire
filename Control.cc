#include "Control.h"
#include "View.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <limits>


// Constructor for the Control object
Control::Control() {

}

// Destructor for the control object
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

// Launch the user interface
void Control::launch(void) {
    // Initialize the random seed
    srand( (unsigned)time( NULL ) );
    // View object
    View view;
    // Declare and initialize the choice
    int choice;
    // Declare and initialize the student attributes
    std::string name;
    int age;
    std::string school;
    // Statically allocate a participant vecotr
    vector<Participant> participants;
    // Declare and initialize has a school booleans
    bool hasHogwarts = false;
    bool hasDurmstrang = false;
    bool hasBeauxbatons = false;

    // Display the main menu
    while (1) {
        view.displayMenu(choice);
        // Get out of the program
        if (choice == 0) {
            break;
        }
        // Add a participant to the Goblet of fire
        else if (choice == 1) {
            // Prompt the user to input their age.
            cout << "You are at the age line. Please enter your age:" << endl;
            cin >> age;
            // Clear the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // If the user is under 17, go back to the main menu
            if (age < 17) {
                cout << "You are not allowed to participate in the Triwizard Tournament. Even if you look older or are under the aging potion, you are still not allowed." << endl;
                continue;
            }
            // Prompt the user to add a name and school
            cout << "Please enter your name:" << endl;
            std::getline(std::cin,name);
            if (name.empty()) {
                cout << "You didn't enter a name" << endl;
                continue;
            }
            cout << endl;
            cout << "Please enter your school:" << endl;
            std::getline(std::cin,school);
            if (school.empty()) {
                cout << "You didn't enter a school" << endl;
                continue;
            }
            cout << endl;
            // If there is a Hogwarts, Beauxbatons, or Durmstrang student added to the list, match the appropriate boolean variable to true
            if (school == "Hogwarts") {
                hasHogwarts = true;
            }
            else if (school == "Beauxbatons") {
                hasBeauxbatons = true;
            }
            else if (school == "Durmstrang") {
                hasDurmstrang = true;
            }
            // Statically allocate a participant object
            Participant p = Participant(name, age, school);
            // Add the participant object to the vector
            participants.push_back(p);
        }
        // Drawing out characters
        else if (choice == 2 && participants.size() >= 3 && (hasHogwarts && hasBeauxbatons && hasDurmstrang))  {
            // Pick a student from Hogwarts
            drawParticipant(participants, "Hogwarts");
            // Pick a student from Beauxbatons
            drawParticipant(participants, "Beauxbatons");
            // Pick a student from Durmstrang
            drawParticipant(participants, "Durmstrang");
            // Mentioning Harry Potter
            // cout << "Harry Potter, (14) from Hogwarts" << endl;
        }
        else if (choice == 2) {
            cout << "Not enough participants" << endl;
        }
    }
}