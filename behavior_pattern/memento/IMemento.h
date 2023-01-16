#include <string>


class IMemento
{
public:
    virtual std::string GetState() = 0;
};
