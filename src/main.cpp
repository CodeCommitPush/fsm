#include "fsm.h"
#include <iostream>
#include <functional>
#include <array>

class CApplication
{
public:    

    // States
    enum
    {
        STATE_INITIAL,
        STATE_IDLE,
        STATE_ACTIVE,
        NUMBER_OF_STATES
    };

    // Transitions
    enum 
    {
        TRANSITION_INIT_TO_IDLE,
        TRANSITION_IDLE_TO_ACTIVE,
        TRANSITION_ACTIVE_TO_IDLE,
        NUMBER_OF_TRANSITIONS
    };    

    // States definition table 
    std::array<CFsm<NUMBER_OF_STATES, NUMBER_OF_TRANSITIONS>::CState, NUMBER_OF_STATES> states = 
    {{
        { [this]() { OnInitialEnter(); }, [this]() { OnInitialExit(); }, "State Initial" },  // STATE_INITIAL
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


    CApplication();
    void OnIdleEnter() { std::cout << "OnIdleEnter() \n"; }
    void OnIdleExit() { std::cout << "OnIdleExit() \n"; }
    void OnInitialEnter() { std::cout << "OnInitialEnter() \n"; }
    void OnInitialExit() { std::cout << "OnInitialExit() \n"; }
    void OnActiveEnter() { std::cout << "OnActiveEnter() \n"; }
    void OnActiveExit() { std::cout << "OnActiveExit() \n"; }
    void Init();

    CFsm<NUMBER_OF_STATES, NUMBER_OF_TRANSITIONS> m_Fsm;
};

CApplication::CApplication()
    : m_Fsm(states, transitions) 
{
}

void CApplication::Init()
{
    m_Fsm.ExecuteTransition(TRANSITION_INIT_TO_IDLE);     
}

int main()
{
    CApplication app;

    app.Init();
    app.m_Fsm.ExecuteTransition(CApplication::TRANSITION_IDLE_TO_ACTIVE);
    app.m_Fsm.ExecuteTransition(CApplication::TRANSITION_ACTIVE_TO_IDLE);
    return 0;
}
