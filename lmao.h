#progma once
#include <iostream>

using namespace std;

namespace out()
{
    void strout(string string)
    {
        cout  << string << endl;
    }
}
namespace math()
{
    template <typename T>
    T sum(T value1, T value2)
    {
        value1 + value2
    }
}