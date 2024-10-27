#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include "funcs.h"
#ifdef _WIN32 
#include <conio.h>
#endif 

int iTest = 888; 

void GetInteger()
{
    int a;
    printf("Please input an integer value: ");
    scanf("%d", &a);
    printf("You entered: %d\n", a);
    return;
}

void AlterTest(int v)
{
    iTest = v;
}

int WriteLn(const void *_Buf, unsigned int Length)
{
    char* NewLine = "\n";
    return Write(_Buf, Length) 
         + Write(NewLine, strlen(NewLine)); 
}
int Write(const void *_Buf, unsigned int Length)
{
    return write (STDOUT_FILENO, _Buf, Length);
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
    getch();
#endif     
}