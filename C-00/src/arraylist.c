#include <stdlib.h>
#include <string.h>
#include "arraylist.h"


ArrayList* ArrayList_New(ArrayListEqualsFunc EqualsFunc, ArrayListCompareFunc CompareFunc)
{    
    ArrayList* Result = (ArrayList*)calloc(1, sizeof(ArrayList));   // ArrayList* Result = (ArrayList*)malloc(sizeof(ArrayList));

	if (Result == NULL) {
		return NULL;
	}

    // initialize - the rest of the members, if any, are zeroed, thanks to calloc()
    Result->_Allocated = 16;
	Result->Count = 0;
	Result->Item = malloc(Result->_Allocated * sizeof(void*)); 
    Result->EqualsFunc = EqualsFunc;
    Result->CompareFunc = CompareFunc;

	if (Result->Item == NULL) {
		free(Result);
		return NULL;
	}

	return Result;
}

void ArrayList_Free(ArrayList* List)
{
    free(List->Item);
    free(List);
}

void ArrayList_Clear(ArrayList* List)
{
	List->Count = 0;    
}

static int ArrayList_IncreaseSize(ArrayList* List)
{ 
    unsigned int NewSize = List->_Allocated * 2;               // double size
	void* Item = realloc(List->Item, sizeof(void*) * NewSize); // Item new size

	if (Item == NULL) {
		return 0;
	} else {
		List->Item = Item;
		List->_Allocated = NewSize;
		return 1;
	}
}

int ArrayList_Insert(ArrayList* List, unsigned int Index, void* Value)
{
	if (Index > List->Count)  
		return 0; 

	if (List->Count + 1 > List->_Allocated) {
		if (!ArrayList_IncreaseSize(List)) {
			return 0;
		}
	}

	/* insert an empty entry at Index position */ 
	memmove(&List->Item[Index + 1],
	        &List->Item[Index],
	        (List->Count - Index) * sizeof(void*));

	/* assign the value */
    List->Item[Index] = Value;
	++List->Count;

	return 1;
}

int ArrayList_Add(ArrayList* List, void* Value)
{
	return ArrayList_Insert(List, List->Count, Value);
}

int ArrayList_IndexOf(ArrayList* List, void* Value)
{

    if (List->EqualsFunc != NULL)
    {
        unsigned int i;

        for (i = 0; i < List->Count; ++i) {
            if (List->EqualsFunc(List->Item[i], Value) != 0)
                return (int) i;
        }
    }

	return -1;
}

 

void ArrayList_Sort(ArrayList* List)
{
    //void qsort( void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*) );
    if (List->CompareFunc != NULL)
    {
        qsort(List->Item, List->Count, sizeof(void*), List->CompareFunc);
    }
}

void* ArrayList_Get(ArrayList* List, unsigned int Index)
{
    if (Index > List->Count - 1)  
		return NULL; 
    return List->Item[Index];
}
void ArrayList_Set(ArrayList* List, unsigned int Index, void* Value)
{
    List->Item[Index] = Value;
}

 
int ArrayList_GetInt(ArrayList* List, unsigned int Index)
{
    return *(int *)List->Item[Index];
}
void ArrayList_SetInt(ArrayList* List, unsigned int Index, int Value)
{
    *(int *)List->Item[Index] = Value;
}