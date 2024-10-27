#ifndef FUNCS_H
#define FUNCS_H

extern int iTest;
 
void AlterTest(int v); 
void GetInteger(); 
int Write(const void *_Buf, unsigned int Length);
int WriteLn(const void *_Buf, unsigned int Length);
void SetWinConsoleToUtf8();
void KeepConsoleOpen();
#endif