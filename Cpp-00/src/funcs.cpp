#include <iostream>
#include <stdio.h>
#include "funcs.hpp"

using namespace std;

namespace project
{

    using namespace std;

    void WriteLine(string Text)
    {
        cout << Text << endl;
    }
    void Write(string Text)
    {
        cout << Text;
    }

    int ReadInteger(string Message)
    {
        WriteLine(Message);
        int value = 0;
        cin >> value;
        return value;
    }

    string ReadString(string Message)
    {
        WriteLine(Message);
        string value = "";
        cin >> value;
        return value;
    }

    string ReadLine(string Message)
    {
        WriteLine(Message);
        char value[96];
        cin.getline(value, sizeof(value) - 1);
        return value;
    }

    void SetWinConsoleToUtf8()
    {
#ifdef _WIN32
        // Change Windows console encoding to UTF-8
        // IMPORTANT: This should be executed before any printf call
        system("chcp 65001  > nul");
#endif
    }

    void KeepConsoleOpen()
    {
#ifdef _WIN32
        WriteLine("Press Enter to terminate");
        cin.get(); // stop and wait for a keystroke
        cin.get();
#endif
    }

}