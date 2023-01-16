#include <vector>
#include "IMemento.h"
#include "Originator.h"

class Caretaker
{


private:
    std::vector<std::shared_ptr<IMemento>> m_pMementos;
    std::shared_ptr<Originator> originator;
};
