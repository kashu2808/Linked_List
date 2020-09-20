#include <stdio.h> 
#include <assert.h>
#include <string.h>
#include "LinkedList.h"
#include "UserData.h"


//PrintLL prints the msg and the content of the linked list
static void PrintLL (char msg[], LLInfoPtr theLL); //declaration of function


// function PrintLLItem is called to print out a message, followed by the contents of a UserData and the allocation count 
static void PrintLLItem (char msg[], UserData D); //declaration of function
 

extern int AllocationCount;  


int main(int argc, const char * argv[]) { 

	UserData DemoData[100]; //array of type user data
	FILE* input; //file pointer
    int x; 
    char task[10]; //character string to store task name
    
 
    input = fopen("testData.txt", "r"); //open the file in read mode
    int i=0; 
    while(fscanf(input,"%d %s", &x,task)>0) {
        DemoData[i].num=x; //the importance int in every line 
        memcpy( DemoData[i].taskName, task, 80 ); //the task name in every line copied in the DemoData array
        
        i++;
    }


	int NumDemoDataItems = i; //number of demo data items equal to the lines in the file

	

    //initalize the information block
	LLInfoPtr LL = LL_Init();


	//print the linked list (since it is empty it will only print allocation count=1)
	PrintLL ("Starting demo.\nAfter the LL has been initialized...", LL); 
	
	//traverse through the Demo data array and add nodes at the front of the linked list
	for (int loop=0; loop < NumDemoDataItems; loop++)     
	     	{         UserData D;        
	     			  D = DemoData[loop];         
	     			  LL_AddAtFront (LL, D);    //add at front 
	     	} 

	//print the linked list
	PrintLL ("After data has been placed at the front of the LL...", LL); 
	
	//delete the linked list
	LL = LL_Delete(LL);     

	//print the list after deleting (linked list is empty )
	PrintLL ("After the LL has been deleted...", LL); 
	
	//initalize the information block
	LL = LL_Init();     PrintLL ("After the LL has been initialized...", LL); 
	
	//traverse through the Demo data array and add nodes at the end of the linked list
	for (int loop = 0; loop < NumDemoDataItems; loop++){         

			UserData D;        
	    	D = DemoData[loop];        
	    	LL_AddAtEnd(LL, D); //add at end   
	 }
	

	
	//print the linked list
	PrintLL ("After data items have been added at the end of the LL...", LL); 
	
	// swap the items in the Linked list 
	//First the data at index 0 and index 3 were swapped and then the data at index 1 and two were swapped.     
	for (int loop = 0; loop < LL_Length(LL)/2; loop++) {       
	  
	  LL_Swap(LL, loop, LL_Length(LL)- loop - 1);   
	  
	  }  
	
	// print out the items in the Linked list     
	PrintLL ("After data has been swapped in the LL...", LL);

    //delete node at the front twice
	for (int loop = 0; loop < 2; loop++) {        
	  		if (LL_Length(LL) > 0){        
	   			
	   			UserData D = LL_GetFront(LL, DELETE_NODE);  //call delete at front  
	   			//print the data that is deleted and allocation count     
	  			PrintLLItem ("A data item has been removed from the front of the LL.. ", D);        
	  	 
	  	 } 

	 }


 	//print the linked list
	PrintLL ("After data has been removed from the LL..", LL);     
 
	 //delete the linked list
 	LL = LL_Delete(LL);    
 
 	//print the linked list
 	PrintLL ("After the LL has been deleted...", LL);     


         return 0;
    }


//printLL definition
void PrintLL (char msg[], LLInfoPtr theLL) {    

 //print the msg,number of nodes and allocation count
 printf ("%s\nThere are now %d items with an allocation count of %d\n",msg, LL_Length(theLL), AllocationCount);     
 
//print the linked list
 	//traverse through the linked list from head to tail
 for (int loop = 0; loop < LL_Length(theLL); loop++) { 
 		//set D as data at loop index         
  		UserData D = LL_GetAtIndex(theLL, loop);   
  		//if loop=head we are at the head       
  		if (loop == 0)             					 	printf  ("Head==> [%d] = %d %s\n", loop, D.num,D.taskName);  
  		//if loop=lenght of ll-1 are at the tail         
  		else if (loop == LL_Length(theLL)-1)            printf  ("Tail==> [%d] = %d %s\n", loop, D.num,D.taskName);  

 		else											printf ("        [%d] = %d %s\n", loop, D.num,D.taskName);     
    } 

  } 
		
//PrintLLItem definition
void PrintLLItem (char msg[], UserData D) {
	//print the msg and Userdata(both intger value and taskName)	
	printf ("%s \nthe UserData contained %d %s\n", msg, D.num,D.taskName); 
	//print the allocation count    
	printf ("The allocation count is now %d\n", AllocationCount);     
	 
	 } 
 


