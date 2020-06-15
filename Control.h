#ifndef CONTROL_H
#define CONTROL_H

#include "Participant.h"
#include "View.h"

#include <vector>
#include <string>
using namespace std;

// This is a control object which controls the user interface and the program
class Control {
    public:
        Control();
        ~Control();
        void launch(void);
        void drawParticipant(vector<Participant*> candidates, string school);
    
    private:
        vector<Participant*> participants;

};

#endif