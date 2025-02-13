#include "fsm.h"
#include <iostream>
#include <functional>

enum 
{
    STATE_INITIAL,
    STATE_IDLE,
    STATE_ACTIVE,
    NUMBER_OF_STATES

};

class CApplication
{    
    std::array<CFsm::CState, NUMBER_OF_STATES> states = 
    {{
        { [this]() { OnInitialEnter(); }, [this]() { OnInitialExit(); },   "State Initial"  },
        { [this]() { OnIdleEnter(); }, [this]() { OnIdleExit(); },   "State Idle"  },
        { [this]() { OnActiveEnter(); }, [this]() { OnActiveExit(); },   "State Idle"  }        
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
    CFsm m_Fsm;

};

CApplication::CApplication() : 
    m_Fsm(states.data())  // Pass pointer to the state array
{
}

void CApplication::Init()
{
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

