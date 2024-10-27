#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist2.h"

 
ArrayList2* ArrayList2_New() {
    const int InitialCapacity = 4;
    ArrayList2* list = (ArrayList2*)malloc(sizeof(ArrayList2));
    list->Item = (void**)malloc(InitialCapacity * sizeof(void*));
    list->Count = 0;
    list->Capacity = InitialCapacity;
    return list;
}
 
void ArrayList2_Free(ArrayList2* list) {
    free(list->Item);
    free(list);
}

void ArrayList2_Clear(ArrayList2* list) {
    list->Count = 0;
}
 
void ArrayList2_Add(ArrayList2* list, void* element) {
    ArrayList2_Insert(list, element, list->Count);
}
 
void ArrayList2_Insert(ArrayList2* list, void* element, int index) {
    if (index < 0 || index > list->Count) {
        //printf("Error: Index out of bounds.\n");
        errno = EDOM;
        return;
    }

    // increase capacity if needed
    if (list->Count >= list->Capacity) {
        list->Capacity *= 2;
        list->Item = (void**)realloc(list->Item, list->Capacity * sizeof(void*));
    }

    //for (int i = list->Count; i > index; i--) 
    //    list->Item[i] = list->Item[i - 1];

	/* insert an empty entry at Index */ 
	memmove(&list->Item[index + 1],
	        &list->Item[index],
	        (list->Count - index) * sizeof(void*));

    list->Item[index] = element;
    list->Count++;
}

void ArrayList2_Remove(ArrayList2* list, void* element) {
    int index = -1;
    for (int i = 0; i < list->Count; i++) {
        if (list->Item[i] == element) {  
            index = i;
            break;
        }
    }

    if (index != -1) {
        ArrayList2_RemoveAt(list, index);
    }
}

void ArrayList2_RemoveAt(ArrayList2* list, int index) {
    
    if (index < 0 || index >= list->Count) {
        //printf("Error: Index out of bounds.\n");
        errno = EDOM;
        return;
    }

    //for (int i = index; i < list->Count - 1; i++)  
    //    list->Item[i] = list->Item[i + 1];

    // remove the entry at Index
	memmove(&list->Item[index],
	        &list->Item[index + 1],
	        (list->Count - (index + 1)) * sizeof(void*));    
 
    list->Count--;
} 

int ArrayList2_IndexOf(ArrayList2* list, void* element) {
    for (int i = 0; i < list->Count; i++) {
        if (list->Item[i] == element) {
            return i;
        }
    }
    return -1;
}
 
int ArrayList2_Contains(ArrayList2* list, void* element) {
    return ArrayList2_IndexOf(list, element) != -1;
}

void ArrayList2_RemoveValue(ArrayList2* list, void* element, int (*equals)(const void*, const void*)) {
    int index = -1;
    for (int i = 0; i < list->Count; i++) {
        if (equals(element, list->Item[i])) {    
            index = i;
            break;
        }
    }

    if (index != -1) {
        ArrayList2_RemoveAt(list, index);
    }
}

int ArrayList2_IndexOfValue(ArrayList2* list, void* element, int (*equals)(const void*, const void*)) {
    for (int i = 0; i < list->Count; i++) {
        //if (list->Item[i] == element) {
        if (equals(element, list->Item[i])) {    
            return i;
        }
    }
    return -1;
}
 
int ArrayList2_ContainsValue(ArrayList2* list, void* element, int (*equals)(const void*, const void*)) {
    return ArrayList2_IndexOfValue(list, element, equals) != -1;
}
 
void* ArrayList2_First(ArrayList2* list) {
    if (list->Count > 0) {
        return list->Item[0];
    }
    return NULL;
}
 
void* ArrayList2_Last(ArrayList2* list) {
    if (list->Count > 0) {
        return list->Item[list->Count - 1];
    }
    return NULL;
}
 
void* ArrayList2_Get(ArrayList2* list, int index) {
    if (index < 0 || index >= list->Count) {
        //printf("Error: Index out of bounds.\n");
        errno = EDOM;
        return NULL;
    }
    return list->Item[index];
}
 
void ArrayList2_Set(ArrayList2* list, int index, void* element) {
    if (index < 0 || index >= list->Count) {
        //printf("Error: Index out of bounds.\n");
        errno = EDOM;
        return;
    }
    list->Item[index] = element;
}
 
void** ArrayList2_ToArray(ArrayList2* list) {
    void** array = (void**)malloc(list->Count * sizeof(void*));
    memcpy(array, list->Item, list->Count * sizeof(void*));
    return array;
}

ArrayList2* ArrayList2_Clone(ArrayList2* list) {
    ArrayList2* result = ArrayList2_New();
    result->Count = list->Count;
    result->Capacity = list->Capacity;
    result->Item = (void**)malloc(result->Capacity * sizeof(void*));
    memcpy(result->Item, list->Item, list->Count * sizeof(void*));
    return result;
}

void ArrayList2_Sort(ArrayList2* list, int (*compare)(const void*, const void*)) {
    qsort(list->Item, list->Count, sizeof(void*), compare);
}

int ArrayList2_CompareInt(const void* a, const void* b) {
    // To be used with qsort() as comparator function.
    // qsort() passes elements, of the array being sorted, as void* to the comparator function,
    // so we end up here with a void** carrying an int value.
    // That is each param of this function is a void pointer to a void pointer, 
    // which actually is an integer pointer
    // thus we need double typecasting and double dereferencing.
    int A = **(int**)a;
    int B = **(int**)b;
    return A - B;
}

int ArrayList2_CompareStr(const void *a, const void *b) 
{ 
  char *A = *(char **)a; 
  char *B = *(char **)b; 
 
  return strcmp(A, B); 
} 
 
int ArrayList2_EqualsInt(const void* a, const void* b)
{ 
    int A = *(int*)a;
    int B = *(int*)b;
    return A == B;
}
