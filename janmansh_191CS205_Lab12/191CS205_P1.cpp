#include<bits/stdc++.h>
using namespace std;

int graph[1000][1000];    // adjacency matrix


int main() {
  
  int i,j,k,n;
  for(i=0;i<1000;i++){
    for(j=0;j<1000;j++)graph[i][j]=0;
  }
  
  cout << "Enter the number of nodes starting from 1 indexing : ";
  cin >> n;
  
  if(n == 1){
    cout << "Spanning tree is : 1\n";
    return 0;
  }
  
  while(1){
    cout << "Enter 1 to add edge and 2 to stop : ";
    cin >> k;
    
    if(k==2)break;
    
    if(k!=1){
      cout << "wrong input, try again\n";
      continue;
    }
    
    int u,v,w;
    
    cout << "Enter the two nodes and weight respectively :  ";
    cin >> u >> v >> w;
    
    if(u == 0 || v ==0 || u > n || v > n || w <= 0){
      cout << "wrong input try again\n";
      continue;
    }
    
    graph[u][v] = w;
    graph[v][u] = w;
  }
  
  set<int>s;
  vector<tuple<int,int,int>>ans;
  
  s.insert(1);
  
  int cost = 0;
  
  while(s.size() < n){
    
    int u=0,v=0,w=INT_MAX;
    
    // taking edge with Minimum weight between tree and non tree vertex
    for(auto it:s){
      for(i=1;i<=n;i++){
        if(binary_search(s.begin(), s.end(), i))continue;
        if(graph[it][i] > 0 && graph[it][i] < w){
          u = it;
          v = i;
          w = graph[it][i];
          //cout << u << " " << v;     //debugging statement
        }
      }
    }
    
    if( v == 0 ){
      cout << "No Spanning Tree exists, graph is not connected i.e. all " << n << " vertices can not be reached from any vertex\n";
      return 0;
    }
      
    s.insert(v);
    ans.push_back(make_tuple(u, v, w));
    cost += w;
    
  }
  
  cout << "Below are the edges of the Minimum Spanning Tree : \n";
  
  for(i=0;i<ans.size();i++){
    cout << get<0>(ans[i]) << " --> " << get<1>(ans[i]) << " , weight : " << get<2>(ans[i]) << "\n";
  }
  
  cout << "The cost of The Minimum Spanning Tree is : " << cost << "\n";
  
	return 0;
}

