#include "Participant.h"

// Participant constructor to create the participant object
Participant::Participant() {

}
// Participant copy constructor to destroy the participant object
Participant::Participant(string n, int a, string h) {
    name = n;
    age = a;
    school = h;
    
}
// This is the destructor
Participant::~Participant() {
    
}

// This is the display info function to display the information of a chosen candidate
void Participant::displayInfo(void) {
    cout << name << ", (" << age << ") from " << school << endl;
}