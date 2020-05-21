#ifndef CONTROL_H
#define CONTROL_H

#include "Participant.h"
#include "View.h"

#include <vector>

class Control {
    public:
        Control();
        ~Control();
        void launch(void);
    
    private:
        vector<Participant> beauxbatons;
        vector<Participant> durmstrang;
        vector<Participant> hogwarts;

};

#endif