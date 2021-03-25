#include<bits/stdc++.h> 
using namespace std;

char pq[6][100];

// Dequeue
void dequeue(int *index){
  
  for(int i=5;i>=1;i--){
    if(index[i] != 0){
      index[i]--;
      return;
    }
  }
  
}

// Enqueuee
void enqueue(char d, int p, int *index){
  
  pq[p][index[p]] = d;
  index[p]++;
  
  return;
}

int main(){
  
  int index[6] = {0}, i;
  
  while(1){
    cout << "Enter '1' to print (printing empties the Queue) , Enter '2' to enqueue, Enter '3' to dequeue, and Enter '0' to exit\n";
    
    int t;
    cin>>t;
    
    char cc;
    int pr;
    
    if(t==2){
      cout<<"Enter data(char) and priority number(1-5 and 5 highest priority) respectively.\n";
      cin>>cc>>pr;
      
      //Enqueue
      enqueue(cc, pr, index);
    }
    
    
    else if(t==1){
      
      int ff=0;
      for(i=0;i<=5;i++){
        if(index[i]!=0){
          ff=1;
          break;
        }
      }
      if(ff==0){
        cout<<"Queue is empty\n";continue;
      }
      
	    for(i=5;i>=1;i--){
	      for(int j=0;j<index[i];j++){
	        cout<<pq[i][j]<<" ";
	      }
	    }
	    for(i=0;i<6;i++)index[i]=0;
	    
	    cout<<"\n";
	    
    }
    
    else if(t==3){
      
      int ff=0;
      for(i=0;i<=5;i++){
        if(index[i]!=0){
          ff=1;
          break;
        }
      }
      if(ff==0){
        cout<<"Queue is empty\n";continue;
      }
      // Dequeue
      dequeue(index);
      
    }
    
    else{
      break;
    }
    
  }
	
	return 0; 
}
