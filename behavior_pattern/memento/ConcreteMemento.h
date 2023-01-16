#include <string>

#include "IMemento.h"

class ConcreteMemento : public IMemento
{
public:
    ConcreteMemento(std::string text) : m_text(text) {}
    virtual ~ConcreteMemento() = default;

    std::string GetState() override
    {
        return m_text;
    }
private:
    std::string m_text;

};
