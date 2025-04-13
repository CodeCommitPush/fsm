#ifndef FSM_MODULE
#define FSM_MODULE

#include <iostream>
#include <functional>
#include <array>

template <std::size_t N, std::size_t M>
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

    CFsm(const std::array<CState, N>& arrStates, const std::array<CTransition, M>& arrTransitions);
    ~CFsm() = default;

    void ExecuteTransision();
    bool SetState(unsigned int state);   

private:
    const std::array<CState, N> m_arrStates;
    const std::array<CTransition, M> m_arrTransitions;    
    unsigned int m_current_state;
};

// Define the constructor inside the header file
template <std::size_t N, std::size_t M>
CFsm<N, M>::CFsm(const std::array<CState, N>& arrStates, 
                 const std::array<CTransition, M>& arrTransitions)
    : m_arrStates(arrStates), m_arrTransitions(arrTransitions), m_current_state(0) 
{
    // Execute on new state enter function
    m_arrStates[m_current_state].onEnter();    
    std::cout << "Initial state is : " << m_arrStates[m_current_state].name <<  std::endl;    
}

template <std::size_t N, std::size_t M>   
void CFsm<N, M>::ExecuteTransision(unsigned int transision)
{        
    if (transision < M)
    {
        const auto& t = m_arrTransitions[transision];

        if (t.fromstate != m_current_state)
        {
            std::cout << "Invalid transition: current state is " 
                      << m_arrStates[m_current_state].name 
                      << ", but transition expects " 
                      << m_arrStates[t.fromstate].name << std::endl;
            return;
        }

        std::cout << "Executing transition " << transision << ": "
                  << m_arrStates[t.fromstate].name << " -> "
                  << m_arrStates[t.tostate].name << std::endl;

        SetState(t.tostate);
    }
    else
    {
        std::cout << "Transition index is out of bounds" << std::endl;
    }
}    

template <std::size_t N, std::size_t M>   
bool CFsm<N, M>::SetState(unsigned int state)
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

