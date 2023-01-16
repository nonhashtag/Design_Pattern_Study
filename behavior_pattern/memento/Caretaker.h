#include <vector>
#include "IMemento.h"
#include "Originator.h"

class Caretaker
{
public:
    Caretaker(std::shared_ptr<Originator> pOriginator) : m_pOriginator(pOriginator) { }
    virtual ~Caretaker() = default;

    void Backup()
    {
        std::cout << "\nCaretaker: Saving Originator's state...\n";
        m_pMementos.push_back(m_pOriginator->Save());
    }

     void Undo()
     {
        if (m_pMementos.empty()) 
            return;
        std::shared_ptr<IMemento> pMemento = m_pMementos.back();
        m_pMementos.pop_back();
        std::cout << "Caretaker: Restoring state to: " << pMemento->GetName() << "\n";
     }


private:
    std::vector<std::shared_ptr<IMemento>> m_pMementos;
    std::shared_ptr<Originator> m_pOriginator;
};
