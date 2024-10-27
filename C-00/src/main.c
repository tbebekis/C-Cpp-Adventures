
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
 
#include "tests.h"
#include "funcs.h"
#include "arraylist2.h"
 
void TestArrayList2() {

    void Display(ArrayList2* List, const char* Message) {
        puts(Message);

        for (int i = 0; i < List->Count; i++)
            printf("%d\n", *(int *)List->Item[i]);
    }

    int V[] = {5, 2, 4, 1, 3};

    ArrayList2* List = ArrayList2_New();

    for (int i = 0; i < 5; i++) { 
        ArrayList2_Add(List, &V[i]); 
    }  

    Display(List, "\nUn-sorted -------------- \n");

    ArrayList2_Sort(List, ArrayList2_CompareInt); 

    Display(List, "\nSorted -------------- \n");

    int x = 3;
    x = ArrayList2_IndexOfValue(List, &x, ArrayList2_EqualsInt); 
    printf("\nIndex Of Value: %d\n", x);

} 

int main() {
    SetWinConsoleToUtf8();
    errno = 0;

    //TestArrayList();
    //TestSort();

    TestArrayList2();
 
    KeepConsoleOpen(); 
    return 0;
}
