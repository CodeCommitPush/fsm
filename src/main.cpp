#include "fsm.h"
#include <iostream>

enum 
{
    STATE_INITIAL,
    STATE_IDLE,
    STATE_ACTIVE

};

class CApplication
{    
    CFsm::CState states[] = {
        {CApplication::OnInitialExit(),   CApplication::OnInitialExit(),  "State Initial" },

    };

    public:
    CApplication();
    void OnIdleEnter() { std::cout << "OnIdleEnter() \n"; }
    void OnIdleExit() { std::cout << "OnIdleExit() \n"; }
    void OnInitialEnter() { std::cout << "OnInitialEnter() \n"; }
    void OnInitialExit() { std::cout << "OnInitialExit() \n"; }
    void Init();
    void Run();

    private:
    CFsm m_Fsm;

};

CApplication:CApplication() : 
    m_Fsm(states)
{


}




int main() 
{
    CApplication app;

    app.Init();
    return 0;
}

