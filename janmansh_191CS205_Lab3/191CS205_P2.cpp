#include<bits/stdc++.h>
using namespace std;

// A linked list 
struct linkedlist{ 
	char data; 
	struct linkedlist* next; 
}; 



void InsertAtBeginning(struct linkedlist *(*head), char new_data){
    
    struct linkedlist* new_node = (struct linkedlist*) malloc(sizeof(struct linkedlist));
    
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
    
    return;
}


void PrintList(struct linkedlist *(*head)){
    
    struct linkedlist* ptr;
    ptr = *head;
    
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    
    cout << "\n";
    return;
}

struct linkedlist* Search(struct linkedlist *(*head), char key){
    
    struct linkedlist* LOC;
    LOC = *head;
    
    while(LOC != NULL){
        if(LOC->data == key){
            return LOC;
        }
        else{
            LOC = LOC->next;
        }
    }
    
    return NULL; //element not found
}


void InsertAfterLOC(struct linkedlist *(*LOC), char new_data){
    
    struct linkedlist* new_node = (struct linkedlist*) malloc(sizeof(struct linkedlist));
    
    new_node->data = new_data;
    new_node->next = (*LOC)->next;
    (*LOC)->next = new_node;
    
    return;
}


void Insert(struct linkedlist *(*head), char new_data, char key){
    
    struct linkedlist* LOC = Search(head, key);   //pointer of the location
    
    if(LOC == NULL){
        cout << "Key not found inserting at the beginning\n";
        InsertAtBeginning(head, new_data);
    }
    
    else{
        cout<< "Inserted after the first Occurrence of the key\n";
        InsertAfterLOC(&LOC, new_data);
    }
}

void DeleteFirstOccurrence(struct linkedlist *(*head), char key){
    
    struct linkedlist* ptr = *head;  //pointer of the current node
    struct linkedlist* prev = NULL;  //pointer of the previous node
    
    while(ptr != NULL){
        if(ptr->data == key){
            if(prev == NULL){
                *head = ptr->next;
            }
            else{
                prev->next = ptr->next;
            }
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    
    return;
}

void DeleteAllOccurrence(struct linkedlist *(*head), char key){
    
    if(Search(head, key) == NULL){
        return;
    }
    
    else{
        DeleteFirstOccurrence(head, key);
        DeleteAllOccurrence(head, key);
    }
    
}


int main(){
    
	struct linkedlist* head = NULL;
	int k;
	char new_data;
	
	while(1){
	    
	    cout << "Enter '1' to insert using a key or Enter '2' to Delete first Occurrence of a key and Enter '3' to Delete all Occurrences of key, Enter '4' to print the linkedlist and Enter '0' to exit\n";
	    cin>>k;
	    
	    if(k==1){
	        cout << "Enter the key after which the element is to be added:\n";
	        char key;
	        cin >> key;
	        cout<< "Enter the new element:\n";
	        cin >> new_data;
	        Insert(&head, new_data, key);
	    }
	    
	    else if(k==2){
	        cout << "Enter the key to be Deleted\n";
	        char key; cin >> key;
	        DeleteFirstOccurrence(&head, key);
	        cout << "Deleted the first Occurrence of " << key << "\n";
	    }
	    
	    else if(k==3){
	        cout << "Enter the key whose all Occurrences are to be Deleted:\n";
	        char key; cin >> key;
	        DeleteAllOccurrence(&head, key);
	        cout << "Deleted all Occurrences of " << key << "\n";
	    }
	    
	    else if(k==4){
	        cout << "The list is as follows: \n";
	        PrintList(&head);
	    }
	    
	    else if(k==0)break;
	    
	    else{
	        cout << "Wrong input\n";
	    }
	}
	return 0;
}

