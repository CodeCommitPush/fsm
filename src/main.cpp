#include "fsm.h"
#include <iostream>
#include <functional>
#include <array>

class CApplication
{
    enum
    {
        STATE_INITIAL,
        STATE_IDLE,
        STATE_ACTIVE,
        NUMBER_OF_STATES
    };

    enum 
    {
        TRANSITION_INIT_TO_IDLE,
        TRANSITION_IDLE_TO_ACTIVE,
        TRANSITION_ACTIVE_TO_IDLE,
        NUMBER_OF_TRANSITIONS
    };    

    // Now use std::array<CFsm<NUMBER_OF_STATES>::CState, NUMBER_OF_STATES>
    std::array<CFsm<NUMBER_OF_STATES, NUMBER_OF_TRANSITIONS>::CState, NUMBER_OF_STATES> states = 
    {{
        { [this]() { OnInitialEnter(); }, [this]() { OnInitialExit(); }, "State Initial" },  // STATE_INITIAL This state will be set as initial state 
        { [this]() { OnIdleEnter(); },    [this]() { OnIdleExit(); },    "State Idle" },     // STATE_IDLE
        { [this]() { OnActiveEnter(); },  [this]() { OnActiveExit(); },  "State Active" }    // STATE_ACTIVE     
    }};

    // Array of transitions
    std::array<CFsm<NUMBER_OF_STATES, NUMBER_OF_TRANSITIONS>::CTransition, NUMBER_OF_TRANSITIONS> transitions = 
    {{
        { STATE_INITIAL, STATE_IDLE }, 
        { STATE_IDLE, STATE_ACTIVE },
        { STATE_ACTIVE, STATE_IDLE }
    }};    

public:
    CApplication();
    void OnIdleEnter() { std::cout << "OnIdleEnter() \n"; }
    void OnIdleExit() { std::cout << "OnIdleExit() \n"; }
    void OnInitialEnter() { std::cout << "OnInitialEnter() \n"; }
    void OnInitialExit() { std::cout << "OnInitialExit() \n"; }
    void OnActiveEnter() { std::cout << "OnActiveEnter() \n"; }
    void OnActiveExit() { std::cout << "OnActiveExit() \n"; }
    void Init();
    void Run();

private:
    CFsm<NUMBER_OF_STATES, NUMBER_OF_TRANSITIONS> m_Fsm;
};

// Constructor: Pass the state array to the CFsm constructor
CApplication::CApplication()
    : m_Fsm(states, transitions)  // Correctly pass the states array to CFsm constructor
{
}

void CApplication::Init()
{
    m_Fsm.SetState(STATE_IDLE);
    m_Fsm.SetState(10);    
}

void CApplication::Run()
{
}

int main()
{
    CApplication app;

    app.Init();

    return 0;
}

