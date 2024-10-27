#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

#include "funcs.hpp"

using namespace std;
using namespace project;

class Man
{
    int fV;

public:
    Man(int V)
    {
        fV = V;
    }
    Man(Man &M)
    {
        fV = M.fV;
    }
};

main()
{
    void SetWinConsoleToUtf8();

    Man M1(2);
    Man M2 = M1;

    KeepConsoleOpen();

    return 0;
}