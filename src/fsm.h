#ifndef FSM_MODULE
#define FSM_MODULE

#include <iostream>
#include <functional>

class CFsm
{
    public:    
    class CState
    {
        public:
            std::function<void()> onEnter;
            std::function<void()> onExit;
            const char* name;
    };  

    class CTransition
    {
        public:
            unsigned int fromstate;
            unsigned int tostate;
    };    

    CFsm(CState* states);
    ~CFsm() = default;

    private:
    CState* p_states;

};

#endif
