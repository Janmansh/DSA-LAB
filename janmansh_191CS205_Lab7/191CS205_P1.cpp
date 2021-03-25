#include<bits/stdc++.h> 
using namespace std; 

// Linked List
typedef struct node{
	char data; 

	int priority; 

	struct node* next; 

} pq; 

// add new element
pq* newNode(char d, int p){ 
  
	pq* temp = (pq*)malloc(sizeof(pq)); 
	temp->data = d;
	temp->priority = p;
	temp->next = NULL;

	return temp; 
} 

//the value with highest priority 
char top(pq** head){
  
	return (*head)->data; 
	
} 

//Pop the element with the  highest priority from the list 
void dequeue(pq** head){
  
	pq* temp = *head; 
	(*head) = (*head)->next;

	return;
} 

//Push according to priority 
void enqueue(pq** head, char d, int p){ 
	pq* start = (*head);

	pq* temp = newNode(d, p);

	if ((*head)->priority < p){ 
		
		temp->next = *head; 
		(*head) = temp; 
	} 
	else{ 
		
		// Traverse the Queue
		while (start->next != NULL && start->next->priority > p){
			start = start->next; 
		} 
		
		temp->next = start->next; 
		start->next = temp; 
	}
	
	return;
} 


int main(){ 
  
  int k=0;
  pq* Qu = NULL;
  
  while(1){
    cout << "Enter '1' to print (printing empties the Queue) , Enter '2' to enqueue, Enter '3' to dequeue, and Enter '0' to exit\n";
    
    int t;
    cin>>t;
    
    char cc;
    int pr;
    
    if(t==2){
      cout<<"Enter data(char) and priority number(1-5 and 5 highest priority) respectively.\n";
      cin>>cc>>pr;
      
    }
    
    if(Qu == NULL){
      k=0;
    }
    
    if(t==2&&k==0){
      Qu = newNode(cc, pr);
      k=1;
    }
    
    else if(t==2){
      
      enqueue(&Qu, cc, pr);
      
    }
    
    else if(t==1){
      
      if(Qu == NULL){
        cout<<"Queue is empty\n";
        continue;
      }
      
	    while(Qu != NULL){ 
		    cout << top(&Qu) << " "; 
		    dequeue(&Qu); 
	    }
	    cout<<"\n";
	    
    }
    
    else if(t==3){
      
      if(Qu == NULL){
        cout<<"Queue is empty\n";
        continue;
      }
      
      dequeue(&Qu);
    }
    
    else{
      break;
    }
    
  }
	
	return 0; 
}
