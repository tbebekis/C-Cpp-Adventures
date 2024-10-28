#include <stdlib.h>
#include "tests.hpp"
#include "funcs.hpp"

using namespace std;

namespace project
{
    string Man::Say()
    {
        return "Man";
    }

    void Man::Test()
    {
        // polymorphism
        Greek g;
        Man *m = &g;
        WriteLine(m->Say());
    }

    string Greek::Say()
    {
        return "Greek";
    }
    Greek::~Greek()
    {
        WriteLine("Greek Destructor");
    }
}