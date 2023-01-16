#include <string>
#include <iostream>
#include <memory>

#include "IMemento.h"
#include "ConcreteMemento.h"

class Originator
{
public:
    Originator(std::string initString) : m_stateString(initString) { std::cout << "Init with : " << initString << "\n"; }

    void DoSomething()
    {
        m_stateString = GenerateRandomString();
        std::cout << "state has been changed to : " << m_stateString << "\n";
    }

    std::shared_ptr<IMemento> Save()
    {
        return std::make_shared<ConcreteMemento>(m_stateString);
    }

    void Restore(IMemento* memento)
    {
        m_stateString = memento->GetState();
        std::cout << "Originator : My state has been restored to " << m_stateString << "\n";
    }


private:
    std::string GenerateRandomString(int length = 10)
    {
        const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        int stringLength = sizeof(alphanum) - 1;

        std::string random_string;
        for (int i = 0; i < length; i++) {
        random_string += alphanum[std::rand() % stringLength];
        }
        return random_string;
    }

private:
    std::string m_stateString;

};
