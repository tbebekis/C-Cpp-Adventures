#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "funcs.h"
#include "arraylist.h"
#include "tests.h"

void TestSort()
{
    // https://www.youtube.com/watch?v=X-mSc_xZXOE

    int CompareFunc(const void* ValueA, const void* ValueB)
    {
        /* it is a void pointer to an integer pointer
        int* X = (int *)ValueA;
        int  x = *X;
        */

        int A = *((int *)ValueA);
        int B = *((int *)ValueB);
        return A - B;
    }

    int List[5];
    for (int i = 0; i < 5; i++)
        List[i] = rand() % 100;

    puts("Un-sorted -------------- \n");
    for (int i = 0; i < 5; i++)
       printf("%d:\t%d\n", i, List[i]);        

    qsort(List, 5, sizeof(int), CompareFunc);

    puts("\nSorted -------------- \n");
    for (int i = 0; i < 5; i++)
       printf("%d:\t%d\n", i, List[i]);
 }

void TestArrayList()
{
    // https://www.youtube.com/watch?v=X-mSc_xZXOE
    int CompareFunc(const void* ValueA, const void* ValueB)
    { 
        /* it is a void pointer to a void pointer, which is actually is an integer pointer
        int* X = *(int **)ValueA;
        int  x = *X;
        */

        int A = **(int **)ValueA;
        int B = **(int **)ValueB;

        return A - B;
    }
    int EqualsFunc(void *ValueA, void *ValueB)
    { 
        int A = *(int*)ValueA;
        int B = *(int*)ValueB;
        return A == B;
    }

    ArrayList* List = ArrayList_New(EqualsFunc, CompareFunc); 

    int x = 5;
    int y = 1;
    int z = 3;

    ArrayList_Add(List, &x);
    ArrayList_Add(List, &y);
    ArrayList_Add(List, &z);

    ArrayList_Sort(List);

    for (int i = 0; i < List->Count; i++)
        printf("%d\n", *(int *)List->Item[i]);
   

    ArrayList_Free(List);
}

 void TestString()
{
    char* name = "ΘεόDωρος";
    WriteLn(name, strlen(name));
    printf("Length: %d", (int)strlen(name));
}
