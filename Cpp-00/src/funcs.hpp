#ifndef FUNCS_H
#define FUNCS_H

#include <string>

namespace project
{
    using namespace std;

    void WriteLine(std::string Text);
    void Write(std::string Text);

    int ReadInteger(std::string Message);
    string ReadLine(string Message);
    string ReadString(std::string Message);

    void SetWinConsoleToUtf8();
    void KeepConsoleOpen();
}
#endif