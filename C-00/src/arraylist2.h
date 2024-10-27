#ifndef ARRAYLIST2_H
#define ARRAYLIST2_H

typedef struct {
    void **Item;        // void pointer to "array" of void pointers, our data
    int Count;          // the current number of valid elements in the array
    int Capacity;       // private member, the actual capacity of the array  
} ArrayList2;

ArrayList2* ArrayList2_New();
void ArrayList2_Free(ArrayList2* list);

void ArrayList2_Clear(ArrayList2* list);

void ArrayList2_Add(ArrayList2* list, void* element);
void ArrayList2_Insert(ArrayList2* list, void* element, int index);
void ArrayList2_Remove(ArrayList2* list, void* element);

void ArrayList2_RemoveAt(ArrayList2* list, int index);
int ArrayList2_IndexOf(ArrayList2* list, void* element);
int ArrayList2_Contains(ArrayList2* list, void* element);

void ArrayList2_RemoveValue(ArrayList2* list, void* element, int (*equals)(const void*, const void*));
int ArrayList2_IndexOfValue(ArrayList2* list, void* element, int (*equals)(const void*, const void*));
int ArrayList2_ContainsValue(ArrayList2* list, void* element, int (*equals)(const void*, const void*));

void* ArrayList2_First(ArrayList2* list);
void* ArrayList2_Last(ArrayList2* list);

void* ArrayList2_Get(ArrayList2* list, int index);
void ArrayList2_Set(ArrayList2* list, int index, void* element);

void** ArrayList2_ToArray(ArrayList2* list);
ArrayList2* ArrayList2_Clone(ArrayList2* list);
void ArrayList2_Sort(ArrayList2* list, int (*compare)(const void*, const void*));

int ArrayList2_CompareInt(const void* a, const void* b);    // to be used in sorting
int ArrayList2_CompareStr(const void *a, const void *b);    // to be used in sorting
int ArrayList2_EqualsInt(const void* a, const void* b);     // to be used when value equality is needed
#endif