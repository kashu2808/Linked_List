#ifndef LINKEDLIST_H_INCLUDED 
#define LINKEDLIST_H_INCLUDED 
#include "UserData.h" // The LL functions use UserData #include "UserData.h" 
 
// The Linked List needs the definition of what a Node is.
// A Node has UserData and linkage information for both "next and "prev" for a doubly linked list 
 
typedef struct node{    
		 UserData Data;    
  		 struct node *next;    
   		 struct node *prev;
 }Node, *NodePtr;

 
//this will be used as Information block of a linked list
 typedef struct {    
  NodePtr Head;  //head of the linked list   
  NodePtr Tail;  //tail of the linked list   
  int     NumNodesInList;   //number of nodes in the linked list 
   } LLInfo, *LLInfoPtr;  

 extern int AllocationCount; //AllocationCount will keep the count of dynamically alocated memory used at a given point

 typedef int ShouldDelete; 
 // ShouldDelete is an enum that has two valid values called DELETE_NODE 
 //and RETAIN_NODE that are used in calling to get user data from the front of the LL typedef 
enum ShouldDelete {DELETE_NODE=1, RETAIN_NODE=2}; 


//all the function defination of the linked list

LLInfoPtr LL_Init();  //initalize linked list by dynamically allocating the information block and set all values as null  

LLInfoPtr LL_Delete(LLInfoPtr LLI_Ptr); //deletes all nodes in the linked list and deallocating the information block

void LL_AddAtFront(LLInfoPtr LLI_Ptr, UserData theData); //add a new node at the front of linked list

void LL_AddAtEnd(LLInfoPtr LLI_Ptr, UserData theData); //add a new node at the end of linked list

UserData LL_GetFront(LLInfoPtr LLI_Ptr, ShouldDelete Choice); //returns the value at front and delete it of choice=1

int LL_Length(LLInfoPtr LLI_Ptr); //returns length of the linked list 

UserData LL_GetAtIndex(LLInfoPtr, int FetchIndex); //returns value at a given index 

void LL_SetAtIndex(LLInfoPtr LLI_Ptr, UserData D, int UpdateIndex); //update value at the given index

void LL_Swap(LLInfoPtr LLI_Ptr, int Index1, int Index2); //swap data of given indices

#endif
 