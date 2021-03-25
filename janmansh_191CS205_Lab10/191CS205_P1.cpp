#include<bits/stdc++.h>
using namespace std;

// A linked list 
struct linkedlist{ 
	char data; 
	struct linkedlist* left;
	struct linkedlist* right;
};

// Searching
pair<struct linkedlist **, struct linkedlist **> BSTSearch(struct linkedlist *(*root), char new_data){
  if((*root)->data == new_data){
    struct linkedlist ** t = NULL;
    return make_pair(root, t);
  }
  
  struct linkedlist * temp0 = (struct linkedlist *)malloc(sizeof(struct linkedlist));
  struct linkedlist * temp1 = (struct linkedlist *)malloc(sizeof(struct linkedlist));
  
  struct linkedlist * temp = (struct linkedlist *)malloc(sizeof(struct linkedlist));
  temp = *root;
  
  int f=0;
  
  while(temp != NULL){
    if(temp->data == new_data){
      f=1;  // Element found
      break;
    }
    temp1 = temp;
    if(new_data > temp->data){
      temp = temp->right;
    }
    else{
      temp = temp->left;
    }
  }
  
  // Element not found
  if(f==0){
    struct linkedlist ** tt = NULL;
    struct linkedlist ** tt1 = NULL;
    return make_pair(tt1, tt);
  }
  
  
  return make_pair(&temp, &temp1); // Element,Parent
  
}


// Inserting a new node  
void BSTInsert(struct linkedlist *( *root), char new_data){
    
    
    // First node
    if(*root == NULL){
 
        struct linkedlist * temp = (struct linkedlist *)malloc(sizeof(struct linkedlist));
 
        temp -> data = new_data;
        *root = temp;
 
        (*root) -> left = NULL;
        (*root) -> right = NULL;
        return;
    }
    
    
    // Element is already present
    if(BSTSearch(root, new_data).first != NULL){
      cout << "Element already present\n";
      return;
    }
    
    struct linkedlist* new_node = (struct linkedlist*) malloc(sizeof(struct linkedlist));
    
    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;
    
    struct linkedlist* node = (struct linkedlist*) malloc(sizeof(struct linkedlist));
    node = *root;

    while(1){
      
      if(new_data > node->data){
        if(node->right == NULL){
          node->right = new_node;
          break;
        }
        else{
          node = node->right;
        }
      }
      
      else{
        if(node->left == NULL){
          node->left = new_node;
          break;
        }
        else{
          node = node->left;
        }
      }
    }
    
    return;
}


// Printing in In-order sequence
void BSTInorderStack(struct linkedlist *(*root)){
  
  stack<struct linkedlist **> s;
  
  s.push(root);
  
  struct linkedlist* node = (struct linkedlist*) malloc(sizeof(struct linkedlist));
  
  node = (*s.top());
  
  // pushing all the left children
  while(node->left != NULL){
    s.push(&(node->left));
    node = node->left;
  }
  
  while(s.size()!=0){
    struct linkedlist* node1 = (struct linkedlist*) malloc(sizeof(struct linkedlist));
    node1 = *s.top();
    char x = node1->data;
    cout << x << " ";
    s.pop();
    if(node1->right!=NULL){
      s.push(&(node1->right));
      struct linkedlist* node2 = (struct linkedlist*) malloc(sizeof(struct linkedlist));
      node2 = *s.top();
      while(node2->left != NULL){
        s.push(&(node2->left));
        node2 = node2->left;
      }
    }
  }
  return;
}


// Deleting a value
void BSTDelete(struct linkedlist *(*root), char key){
  
  struct linkedlist* node = (struct linkedlist*) malloc(sizeof(struct linkedlist));
  struct linkedlist* parent = (struct linkedlist*) malloc(sizeof(struct linkedlist));
  
  // Element not found
  if(BSTSearch(root, key).first == NULL){
    cout<<"Element not found\n"; return;
  }
  node = *(BSTSearch(root, key).first);
  
  // Element is root so parent is NULL
  if(BSTSearch(root, key).second == NULL){
    parent = NULL;
  }
  
  else{
    parent = *(BSTSearch(root, key).second);
  }
  
  
  if(node->left == NULL && parent != NULL){
    if(parent->left == node){
      parent->left = node->right;
    }
    else{
      parent->right = node->right;
    }
    return;
  }
  
  if(node->right == NULL && parent != NULL){
    if(parent->left == node){
      parent->left = node->left;
    }
    else{
      parent->right = node->left;
    }
    return;
  }
  
  // parent of minimum value on the right subtree of the key element
  struct linkedlist* prev = (struct linkedlist*) malloc(sizeof(struct linkedlist));
  
  // minimum value on the right subtree of the key element
  struct linkedlist* temp = (struct linkedlist*) malloc(sizeof(struct linkedlist));
  
  prev = node;
  temp = prev->right;
  
  if(temp->left == NULL){
    node->data = node->right->data;
    node->right = node->right->right;
    return;
  }
  
  while(temp->left != NULL){
    prev = temp;
    temp = temp->left;
  }
  
  node->data = temp->data;
  prev->left = NULL;
  
  return;
}


int main(){
    
	struct linkedlist* root = NULL;
	int k;
	char new_data;
	
	while(1){
	    
	    cout << "Enter '1' to insert an element to the tree or Enter '2' to delete an element, Enter '3' to print the tree in inorder, Enter '4' to Search an element in the tree, and Enter '0' to exit\n";
	    cin>>k;
	    
	    if(k==1){
	        cout<< "Enter the new element: ";
	        cin >> new_data;
	        BSTInsert(&root, new_data);
	    }
	    
	    else if(k==2){
	      cout << "Enter the element to be deleted: ";
	      cin >> new_data;
	      BSTDelete(&root, new_data);
	    }
	    
	    else if(k==3){
	      cout << "The inorder tree is as follows: \n";
	      BSTInorderStack(&root);
	      cout<<"\n";
	    }
	    
	    else if(k==4){
	        cout << "Enter the element to be searched: ";
	        cin >> new_data;
	        struct linkedlist* nnode = (struct linkedlist*) malloc(sizeof(struct linkedlist));
	        if(BSTSearch(&root, new_data).first == NULL){
	          cout << "Element not found\n";
	        }
	        else{
	          cout << "Element found\n";
	        }
	    }
	    
	    else if(k==0)break;
	    
	    else{
	        cout << "Wrong input\n";
	    }
	}
	return 0;
}

