#include<bits/stdc++.h>
using namespace std;

// A linked list 
struct linkedlist{ 
	char data; 
	struct linkedlist* left;
	struct linkedlist* right;
}; 


// Inserting a new node  
void Insert(struct linkedlist *(*root), int new_data){
    
    
    // First node
    if(*root == NULL){
 
        struct linkedlist * temp = (struct linkedlist *)malloc(sizeof(struct linkedlist));
 
        temp -> data = new_data;
        *root = temp;
 
        (*root) -> left = NULL;
        (*root) -> right = NULL;
        return;
    }
    
    struct linkedlist* new_node = (struct linkedlist*) malloc(sizeof(struct linkedlist));
    
    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;
    
    queue<struct linkedlist **> q;    // Queue for traversing the tree
    q.push(root);                     // Pushing root in the Queue
    
    while(q.size()!=0){
      
      struct linkedlist* node = (struct linkedlist*) malloc(sizeof(struct linkedlist));
      node = *q.front();
      q.pop();
      
      if(node->left == NULL){
        node->left = new_node;
        return;
      }
      
      if(node->right == NULL){
        node->right = new_node;
        return;
      }
      
      q.push(&((node)->left));          // Pushing left child
      q.push(&((node)->right));         // Pushing right child
    }
    
    return;
}

// Returning the height of the tree
int height(struct linkedlist *(*root)){
  
  if((*root) == NULL) return(-1);
  
  // Leaf node
  if((*root)->left == NULL && (*root)->right == NULL){
    return 0;
  }
  
  return max( height( &((*root)->left) ) + 1, height( &((*root)->right) ) + 1);
}

// Printing in Pre-order sequence
void preorder(struct linkedlist *(*root)){
  
  if(*root == NULL) return;
  
  int ans=(*root)-> data;
  cout << ans << " ";
  
  preorder(&(*root)->left);
  preorder(&(*root)->right);
  
  return;
}


// Printing in In-order sequence
void inorder(struct linkedlist *(*root)){
  
  if(*root == NULL) return;
  
  inorder(&((*root)->left));
  
  int ans=(*root)-> data;
  cout << ans << " ";
  
  inorder(&((*root)->right));
  
  return;
}

// Printing in Post-order sequence
void postorder(struct linkedlist *(*root)){
  
  if(*root == NULL) return;
  
  postorder(&(*root)->left);
  postorder(&(*root)->right);
  
  int ans=(*root)-> data;
  cout << ans << " ";
  
  return;
}


int main(){
    
	struct linkedlist* root = NULL;
	int k;
	int new_data;
	
	while(1){
	    
	    cout << "Enter '1' to insert an element to the tree or Enter '2' to get the height of tree and Enter '3' to print the tree in preorder, Enter '4' to print the tree in inorder, Enter '5' to print the tree in postorder, and Enter '0' to exit\n";
	    cin>>k;
	    
	    if(k==1){
	        cout<< "Enter the new element:\n";
	        cin >> new_data;
	        Insert(&root, new_data);
	    }
	    
	    else if(k==2){
	        cout << "The height of the tree is: ";
	        int ht = height(&root);
	        cout << ht << "\n";
	    }
	    
	    else if(k==3){
	        cout << "The preorder tree is as follows: \n";
	        preorder(&root);
	        cout<<"\n";
	    }
	    
	    else if(k==4){
	      cout << "The inorder tree is as follows: \n";
	      inorder(&root);
	      cout<<"\n";
	    }
	    
	    else if(k==5){
	      cout << "The postorder tree is as follows: \n";
	      postorder(&root);
	      cout<<"\n";
	    }
	    
	    else if(k==0)break;
	    
	    else{
	        cout << "Wrong input\n";
	    }
	}
	return 0;
}

