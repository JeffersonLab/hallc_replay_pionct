#include <iostream>
template <typename T>
class range
{

private: 
    T m_min{};
    T m_max{}; 
public: 
    range (T min, T max)
    : m_min{min}, m_max{max}
    {

    }
    void SetMin(T min) {m_min = min;}
    void SetMax(T max) {m_max = max;}

    T GetMin() const {return m_min;}
    T GetMax() const {return m_max;}

    void print() const 
    {
        std::cout << "Min: " << m_min << " Max: " << m_max; 
    }
    
};