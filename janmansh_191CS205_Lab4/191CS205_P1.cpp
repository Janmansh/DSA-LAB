#include<bits/stdc++.h>
using namespace std;

// A linked list 
struct linkedlist{ 
	char data; 
	struct linkedlist* next; 
}; 



void InsertAtBeginning(struct linkedlist *(*tail), char new_data){
    
    if(*tail == NULL){
 
        struct linkedlist *temp = (struct linkedlist*)malloc(sizeof(struct linkedlist));
 
        temp -> data = new_data;
        *tail = temp;
 
        (*tail) -> next = *tail;
        return;
    }
    
    struct linkedlist* new_node = (struct linkedlist*) malloc(sizeof(struct linkedlist));
    
    new_node->data = new_data;
    new_node->next = (*tail)->next;
    (*tail)->next = new_node;
    
    return;
}


void PrintList(struct linkedlist *(*tail)){
    
    struct linkedlist* ptr;
    
    if (tail == NULL){
        cout << "List is empty." << endl;
        return;
    }
 
    // Pointing to first Node of the list.
    ptr = (*tail)->next;
 
    // Traversing the list.
    cout << ptr->data << " ";
    ptr = ptr->next;
    
    while(ptr != (*tail)->next){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    
    cout << "\n";
    return;
}

struct linkedlist* Search(struct linkedlist *(*tail), char key){
    
    if (tail == NULL){
        cout << "List is empty." << endl;
        return NULL;
    }
    
    struct linkedlist* LOC;
    LOC = (*tail)->next;
    
    if(LOC->data == key){
        cout << "Key is present\n";
        return LOC;
    }
    
    LOC = LOC->next;

    while(LOC != (*tail)->next){
        if(LOC->data == key){
            cout << "Key is present\n";
            return LOC;
        }
        else{
            LOC = LOC->next;
        }
    }
    cout << "Key not found\n";
    
    return NULL; //element not found
}


int main(){
    
	struct linkedlist* tail = NULL;
	int k;
	char new_data;
	
	while(1){
	    
	    cout << "Enter '1' to insert an element at the beginning or Enter '2' to search the Occurrence of a key and Enter '3' to print the linkedlist and Enter '0' to exit\n";
	    cin>>k;
	    
	    if(k==1){
	        cout<< "Enter the new element:\n";
	        cin >> new_data;
	        InsertAtBeginning(&tail, new_data);
	    }
	    
	    else if(k==2){
	        cout << "Enter the key to be Searched\n";
	        char key; cin >> key;
	        Search(&tail, key);
	    }
	    
	    else if(k==3){
	        cout << "The list is as follows: \n";
	        PrintList(&tail);
	    }
	    
	    else if(k==0)break;
	    
	    else{
	        cout << "Wrong input\n";
	    }
	}
	return 0;
}

