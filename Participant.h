#ifndef PARTCIPANT_H_
#define PARTICIPANT_H_

#include <string.h>
#include <iostream>

// This is the participant class. It represents a candidate to be chosen for the Triwizard Tournament
// An example of a candidate is Cedric Diggory.
class Participant {
    public:
        Participant();
        Participant(string n, int a, string s);
        ~Participant();
        void displayInfo(void);
    
    private:
        string name;
        int age;
        string school;

}
