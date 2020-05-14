#include "Participant.h"

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

}