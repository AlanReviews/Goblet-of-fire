#include "Participant.h"

// Participant constructor to create the participant object
Participant::Participant() {

}

// Participant copy constructor to create the participant object
Participant::Participant(string n, int a, string s) {
    name = n;
    age = a;
    school = s;
    
}

// This is the destructor to destroy the participant object
Participant::~Participant() {
    
}

// Getters for the name, age, and school
string Participant::getName(void) const { return name; }
int Participant::getAge(void) const { return age; }
string Participant::getSchool(void) const { return school; }

// This is the display info function to display the information of a chosen candidate
void Participant::displayInfo(void) {
    cout << getName() << ", (" << getAge() << ") from " << getSchool() << endl;
}