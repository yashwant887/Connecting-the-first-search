#include <iostream>
#include<bits/stdc++.h>
using namespace std;



void findTopoSort(int node, vector<bool> visited, queue<int> &q, vector<vector<int>> adj){
  visited[node] = true;

  for(int it: adj[node]){
    if(!visited[it]) {
      findTopoSort(it,visited,q,adj);
    }
  }
  q.push(node);
}

vector<int> topoSort(int N, vector<vector<int>> adj){
  queue<int> q;
  vector<bool> visited(N, false);
  for(int i =0; i<N;i++) {
    if(visited[i] == false){
      findTopoSort(i,visited,q,adj);
    }
  }
  vector<int> topo;
  while(!q.empty()){
    topo.push_back(q.top());
    q.pop();
  }
  return topo;
}

int main() {
  
}