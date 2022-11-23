#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
#if 1
    Base()
    :_dbase(0)
    {
        cout << "Base()" << endl;
    }
#endif
    Base(double dbase)
    :_dbase(dbase)
    {
        cout << "Base(double)" << endl;
    }
private:
    double _dbase;
};

class Derived
: public Base
{
public:
    Derived()
    : Base()
    , _dderived(0)
    {
        cout << "Derived(0)" << endl;
    }
#if 0
    Derived(double dderived)
    : Base()
    , _dderived(dderived)
    {
        cout << "Derived(double)" << endl;
    }
#endif
private:
    double _dderived;
};

int main(int argc, char **argv)
{
    Derived d;
    return 0;
}
