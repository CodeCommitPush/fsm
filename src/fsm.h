#ifndef FSM_MODULE
#define FSM_MODULE

#include <iostream>
#include <functional>
#include <array>

template <std::size_t N>
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

    CFsm(const std::array<CState, N>& arrStates);
    ~CFsm() = default;

    void ExecuteTransision();
    bool SetState(unsigned int state);   

private:
    const std::array<CState, N> m_arrStates;
    unsigned int m_current_state;
};

// Define the constructor inside the header file
template <std::size_t N>
CFsm<N>::CFsm(const std::array<CState, N>& arrStates)
    : m_arrStates(arrStates), m_current_state(0) 
{
    // Execute on new state enter function
    m_arrStates[m_current_state].onEnter();    
    std::cout << "Initial state is : " << m_arrStates[m_current_state].name <<  std::endl;    
}

template <std::size_t N>    
void CFsm<N>::ExecuteTransision()
{    
   
}    

template <std::size_t N>    
bool CFsm<N>::SetState(unsigned int state)
{
    bool result = false;
    if (state < N)
    {
        // Execute on current state exit function
        m_arrStates[m_current_state].onExit();

        // Execute on new state enter function
        m_arrStates[state].onEnter();        

        std::cout << "State changed: " << m_arrStates[m_current_state].name << " -> " << m_arrStates[state].name << std::endl;

        // Update the current state 
        m_current_state = state;
        
        result = true;
    }
    else
    {
        std::cout << "State index is out of boundary"  << std::endl;

    }

    return result;
}    


#endif

