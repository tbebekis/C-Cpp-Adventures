#ifndef ARRAYLIST_H
#define ARRAYLIST_H
 

typedef int (*ArrayListEqualsFunc)(void* ValueA, void* ValueB);
typedef int (*ArrayListCompareFunc)(const void* ValueA, const void* ValueB); // qsort comparator
 

typedef struct  {
    void** Item;
    unsigned long Count;
    unsigned long _Allocated;           // private member
    ArrayListEqualsFunc EqualsFunc;
    ArrayListCompareFunc CompareFunc;
} ArrayList;


// methods
ArrayList* ArrayList_New(ArrayListEqualsFunc EqualsFunc, ArrayListCompareFunc CompareFunc);
void ArrayList_Free(ArrayList* List);
int ArrayList_Insert(ArrayList* List, unsigned int Index, void* Value);
int ArrayList_Add(ArrayList* List, void* Value);
int ArrayList_IndexOf(ArrayList* List, void* Value);
void ArrayList_Sort(ArrayList* List);

void* ArrayList_Get(ArrayList* List, unsigned int Index);
void ArrayList_Set(ArrayList* List, unsigned int Index, void* Value);

int ArrayList_GetInt(ArrayList* List, unsigned int Index);
void ArrayList_SetInt(ArrayList* List, unsigned int Index, int Value);
 
#endif