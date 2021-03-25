#include<bits/stdc++.h>
using namespace std;

int digraph[1000][1000]={0}, graph[1000][1000];
char data[1000];

// insertion
void Insert(int start, int end){
  digraph[start][end] = 1;
  graph[start][end] = 1;
  graph[end][start] = 1;
}


// Displaying Nodes reachable from index start 
void BFS_Display(int start, int n){
  
  cout << "Nodes in BFS manner reachable from " << start << "are as follows: ";
  int visited[1000]={0};
  queue<int> q;
  
  q.push(start);
  visited[start] = true;
  
  while (!q.empty()) {
    
    int vis = q.front();
    cout << vis << "(" << data[vis] << ") ";
    q.pop();
    
    for(int i = 1; i <= n; i++) {
      
      if (digraph[vis][i] == 1 && (!visited[i])) {
        q.push(i);
        visited[i] = true;
      }
      
    }
    
  }
  
  cout<<"\n";
}


// Searching key element from start
void BFS_Search(int start, int key, int n){
  
  if(key > n || key == 0){
    cout << "Node: "<<key << " Not present in the graph\n";
    return;
  }
  
  int visited[1000]={0};
  queue<int> q;
  q.push(start);
  visited[start] = true;
  int parent[n+1]={0};      // storing parent to backtrack and find path if any
  parent[start] = -1;
  vector<int>v;
  int f=0;                //flag to check if element is present
  
  while (!q.empty()) {
    int vis = q.front();
    q.pop();
    for(int i = 1; i <= n; i++) {
      if (digraph[vis][i] == 1 && (!visited[i])) {
        q.push(i);
        visited[i] = true;
        if(parent[i]==0){
          parent[i] = vis;
        }
        if(i==key){
          f=1;
          break;
        }
      }
    }
    if(f)break;
  }
  
  if(f==0){
    cout << "Node: " << key <<" present in the graph, but not in the tree starting at index: "<<start<<"\n";
    return;
  }
  
  int cur = key;
  v.push_back(key);
  
  while(parent[cur]>0){
    v.push_back(parent[cur]);
    cur = parent[cur];
  }
  
  cout << "The path from "<<start<<" to "<<key<<" is: ";
  
  for(int i = v.size()-1; i>0; i--){
    cout << v[i] <<"(" << data[v[i]] << ")->";
  }
  
  cout<<v[0]<<"("<<data[v[0]]<<")\n";
  
  return;
}


// Check if Graph is connected or not
void BFS_Connect(int n){
  
  int visited[1000]={0};
  
  queue<int> q;
  q.push(1);
  visited[1] = true;
  
  while (!q.empty()) {
    int vis = q.front();
    q.pop();
    for(int i = 1; i <= n; i++) {
      if (graph[vis][i] == 1 && (!visited[i])) {
        q.push(i);
        visited[i] = true;
      }
    }
  }
  
  for(int i=1;i<=n;i++){
    if(visited[i]==0){
      cout<<"Graph is not connected\n";
      return;
    }
  }
  
  cout<<"Graph is connected\n";
  
  return;
}



int main(){
  
	int k;
	char new_data;
	
	int n;
	
	cout << "Enter the Number of nodes: "; cin >> n;
	for(int i=0;i<n;i++){
	  cout<<"Enter data of node "<< i+1<<": ";
	  cin>>new_data;
	  data[i+1]=new_data;
	}
	
	while(1){
	    
	    cout << "Enter '1' to insert an edge to the graph or Enter '2' to display the graph, Enter '3' to Search the graph, Enter '4' to check if graph is connected, and Enter '0' to exit\n";
	    cin>>k;
	    
	    if(k==1){
	        cout<< "Enter the starting index(eg: 1, 2 ) and end index(eg: 1, 2 ) not more than N = "<<n<<" respectively: ";
	        int start,end;
	        cin >> start >> end;
	        if(start > n || end > n){
	          cout << "Entered index greater than N\n";
	          continue;
	        }
	        Insert(start, end);
	    }
	    
	    else if(k==2){
	      cout << "Enter the index(eg: 1, 2 ) not more than N = "<<n<<" from where the reachable nodes should be displayed: ";
	      int start;
	      cin>>start;
	      if(start > n){
	        cout << "Entered node does not exist\n";
	        continue;
	      }
	      BFS_Display(start, n);
	    }
	    
	    else if(k==3){
	      cout << "Enter the source index and element index to be searched(eg: 1, 2 ) not more than N = "<<n<<" respectively: ";
	      int start,key;
	      cin >> start >> key;
	      BFS_Search(start, key, n);
	    }
	    
	    else if(k==4){
	        BFS_Connect(n);
	    }
	    
	    else if(k==0)break;
	    
	    else{
	        cout << "Wrong input, try again\n";
	    }
	}
	return 0;
}
