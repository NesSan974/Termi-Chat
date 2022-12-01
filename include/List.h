#ifndef __LIST__
#define __LIST__


typedef struct List 
{
    void* data;
    struct List* next;

} List, Cell;


List* AddtoList(List*, int, void*);
int GetLenghtList(List*);
void* GetElemInList(List*, int);
int isListEmpty(List*);
List* DestroyList(List*);
void ModifyElemInList(List* , int , void* );
List* DeleteElemInList(List*, int);



#endif