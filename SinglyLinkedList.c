#include <stdlib.h>  //standard library for general purpose
#include <assert.h> //used to verify assumptions made by the program
 #include "UserData.h" //userdefined datatype(this will be used as argument in functions)
#include "LinkedList.h" //declaration of all linked list functions
 int AllocationCount = 0; //Allocation count is set to zero ()

 static NodePtr MakeNode (UserData theData); //declaration of MakeNode


//LL_Init function is used to initialize the Information Structure 
 LLInfoPtr LL_Init(){

 LLInfoPtr LLI_Ptr = (LLInfoPtr) malloc (sizeof (LLInfo));   //dynamic allocation of Information Structure
  
 assert (LLI_Ptr != NULL); 

  // Initialize the data in the struct just allocated     
  LLI_Ptr->Head = NULL;  //head is set tu null since there is no node    
  LLI_Ptr->Tail = NULL;  //tail is set tu null since there is no node 
  LLI_Ptr->NumNodesInList = 0;   //NumNodesInList is set to null since there is no node  
 
  AllocationCount++; //allocation count is increased by 1 since malloc is used once
  
  return LLI_Ptr; //returning the information structure
  }

 //LL_Delete is called to delete all of the nodes in the Linked 
 //steps to delete all nodes
 //step 1- make sure the information structure exist using assert()
 //step 2-  traverse through the linked list and delete the front node using LL_GetFront function
 //step 3- delete the information structure using free()
 //step 4- decrese the Allcation count by 1(since free() is used)
 //step 5- return a NULL because the list structure no longer exists 

LLInfoPtr LL_Delete(LLInfoPtr LLI_Ptr) {    
  assert (LLI_Ptr != NULL);    
  while (LLI_Ptr->NumNodesInList != 0){
	   LL_GetFront(LLI_Ptr, DELETE_NODE);   
  }  
  free(LLI_Ptr);

  LLI_Ptr = NULL;

  AllocationCount--;     

  return NULL;
}


// LL_AddAtFront is called to add the UserData as a node to the front of the LinkedList
//steps to Add at front
//step 1- make sure the information structure exist using assert()
//step 2- Create a new node using  the local functon MakeNode()
//step 3- if the head is not equal to null(i.e atlease one node already exist in the linked list) make the NewNode's next equal to the head
//step 4- if NumNodesInList = 0(i.e linked list was currently empty) make the new node the tail of the linked list
//step 5- make the new node the head of the linked list
//step 6- increase the NumNodesInList by 1 since a new node is added to the linked list
void LL_AddAtFront (LLInfoPtr LLI_Ptr, UserData theData) {         
assert (LLI_Ptr != NULL); 

NodePtr NewNode = (NodePtr) MakeNode(theData); 

if (LLI_Ptr->Head != NULL){  NewNode->next = LLI_Ptr->Head; }

if (LLI_Ptr->NumNodesInList == 0){ LLI_Ptr->Tail = NewNode; }
 
LLI_Ptr->Head = NewNode;    
 
LLI_Ptr->NumNodesInList++;     

return; 
}

// LL_GetFront is called to return the user data at the front of the linked list and delete it if require
//if Choice is RETAIN_NODE it wont delete the node,if choice is DELETE_NODE function will delete the node*/

//steps 
//step 1- assert that the information structue exist
//step 2- assert there is atleast 1 node in the linked list
//step 3- assert that choice is DELETE_NODE or RETAIN_NODE
//step 4- copy the user data in a new variabe
//if(choice is to delete the node)
//step 5- update Head to point to the next node
//step 6- deallocate the current start of the Linked list
//step 7- decrese the Allcation count by 1(since free() is used)
//step 8- decrease the NumNodesInList by 1 since a node is deleted
//step 9- return the user data that was read at the start  

UserData LL_GetFront (LLInfoPtr LLI_Ptr, ShouldDelete Choice) {

assert (LLI_Ptr != NULL);     
assert (LLI_Ptr->Head != NULL);

assert (Choice == DELETE_NODE || Choice == RETAIN_NODE);     

NodePtr top = LLI_Ptr->Head;    

UserData D = top->Data;     

if (Choice == DELETE_NODE) {                 

LLI_Ptr->Head = top->next;         

free (top);         

top = NULL;         

AllocationCount--;         

LLI_Ptr->NumNodesInList--;            

if (LLI_Ptr->NumNodesInList == 0) LLI_Ptr->Head = LLI_Ptr->Tail = NULL;     

}
return D; 

}

// LL_AddAtEnd is called to add the UserData as a node to the End of the LinkedList
//steps to Add at End
//step 1- make sure the information structure exist using assert()
//step 2- if Head of node=null (i.e no node in the linked list) call the LL_AddAtFront function 
//step 3- create a Node pointer and make it equal to head
//step 4- move the pointer forward until we reach to the end of the node
//step 5- make a node using MakeNode function to insert and link it to the current last node 
//step 6- make this node the new tail by upadating the Information structure
//step 7- increase the NumNodesInList by 1 since a new node is added to the linked list

void LL_AddAtEnd (LLInfoPtr LLI_Ptr, UserData theData) { 
assert (LLI_Ptr != NULL);     
if (LLI_Ptr->Head == NULL){
  LL_AddAtFront(LLI_Ptr, theData);
  }

else {       
 NodePtr EndNode = LLI_Ptr->Head;         
 
 while (EndNode->next != NULL) EndNode = EndNode->next;             
 
 NodePtr NewNode = (NodePtr) MakeNode(theData);         
 
 EndNode->next = NewNode;         
 
 LLI_Ptr->Tail = NewNode;          
 
 LLI_Ptr->NumNodesInList++;

  } 
} 

//LL_Length returns the current length of the linked list 
int  LL_Length  (LLInfoPtr LLI_Ptr) {   
  //returns 0 if information structure is null and NumNodesInList if it is'nt null.     
  return (LLI_Ptr == NULL) ? 0 : LLI_Ptr->NumNodesInList; 

} 


//LL_GetAtIndex is used to get the data at a given index
UserData  LL_GetAtIndex (LLInfoPtr LLI_Ptr, int FetchIndex) {   

assert (LLI_Ptr != NULL); //make sure the new node is not null    
assert ((FetchIndex >= 0) && (FetchIndex < LLI_Ptr->NumNodesInList) ); //make sure the given indiex is >=1 1 and < NumNodesInList 

int DesiredNodeCount = FetchIndex;      
NodePtr DesiredNode = LLI_Ptr->Head; //set a DesiredNode pointer equal to head
  


//move forward for  DesiredNodeCount times 
while (DesiredNodeCount--){   
 	  DesiredNode = DesiredNode->next; //move to the next node
 }
  
return DesiredNode->Data; //return the value in the desired node

} 


void  LL_SetAtIndex (LLInfoPtr LLI_Ptr, UserData D, int UpdateIndex) {    


assert (LLI_Ptr != NULL); //make sure the new node is not null    
assert ((UpdateIndex >= 0) && (UpdateIndex < LLI_Ptr->NumNodesInList) ); //make sure the given indiex is >=1 1 and < NumNodesInList   


int DesiredNodeCount = UpdateIndex;   //set DesiredNodeCount equal to the updateIndex
NodePtr DesiredNode = LLI_Ptr->Head;  //set a DesiredNode pointer equal to head

//move forward for  DesiredNodeCount times  
while (DesiredNodeCount--) { 
  DesiredNode = DesiredNode->next; 
}    
 

DesiredNode->Data = D; //set the Data of Desired node equal to the D (D is passed as argument in this function)
  }




  void  LL_Swap (LLInfoPtr LLI_Ptr, int Index1, int Index2) {   
  assert (LLI_Ptr != NULL);    //make sure the informaton structure is not null
  
  //make sure the given indices are greater than or equal to one and less than NumNodesInList 
  assert ((Index1 >= 0) && (Index1 < LLI_Ptr->NumNodesInList) ); 
  assert ((Index2 >= 0) && (Index2 < LLI_Ptr->NumNodesInList) ); 
  

   //if both indices are same there is no need to do anything
   if (Index1 == Index2) return; 
  
  UserData Index1Data = LL_GetAtIndex(LLI_Ptr, Index1);  //store the value at index 1 in Index1Data
  UserData Index2Data = LL_GetAtIndex(LLI_Ptr, Index2);  //store the value at index 2 in Index2Data
  
  LL_SetAtIndex (LLI_Ptr,Index2Data, Index1);     //set index 1 value equal to Index2Data
  LL_SetAtIndex(LLI_Ptr, Index1Data, Index2);     //set index 2 value equal to Index1Data  
   
  return; 

  } 


   NodePtr MakeNode (UserData theData) {   
   NodePtr NewNode = (NodePtr) malloc (sizeof (Node)); //a node created dynamically using malloc    
   
   assert (NewNode != NULL);   //make sure the new node is not null
   
   NewNode->Data = theData;     //set new node Data equals thedata
   
   NewNode->next = NULL;   //set new node->next equal to NULL
   
   AllocationCount++;  //since malloc() is used once increase AllocationCount by 1
   
   return NewNode; //return the new node
   }