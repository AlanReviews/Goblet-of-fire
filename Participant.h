#ifndef PARTCIPANT_H_
#define PARTICIPANT_H_

#include <string>
using namespace std;
#include <iostream>

// This is a participant object. It is an entity object. It represent a student at a school in the Harry Potter universe.
class Participant {
    public:
        Participant();
        Participant(string n, int a, string s);
        string getName(void) const;
        int getAge(void) const;
        string getSchool(void) const;
        ~Participant();
        void displayInfo(void);
        
    
    private:
        string name;
        int age;
        string school;

};

#endif