#ifndef PARTCIPANT_H_
#define PARTICIPANT_H_

#include <string.h>
#include <iostream>

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