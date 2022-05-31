#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<bool> visited, queue<int> q, vector<vector<pair<int,int>>> adj){
  visited[node] = true;
  for(auto it : adj[node]){
    if(!visited[it.first]) {
      findTopoSort(it.first, visited, q, adj);
    }
    
  }
  q.push(node);
}
// src is source
void shortestPath(int src, int N,vector<vector<pair<int,int>>> adj)  {
  bool visited[N] = false;
  queue<int> q;
  for(int i = 0; i<N ;i++) {
    if(!visited[i]) {
      findTopoSort(i, visited , q ,adj);
    }
  }
    int dist[N];
    for(int i =0 ; i< N ; i++) {
      dist[i]= INT_MAX;
      dist[src] = 0;
    }
    while(!q.empty()){
      int node = q.back();
      q.pop();
    }
    if(dist[node]!= INT_MAX) {
      for(auto it : adj[node]) {
        if(dist[node] + it.second < dist[it.first]) {
          dist[it.first] = dist[node] + it.second;
        }
      }
    }
  
  for(int i=0;i<N;i++) {
    if(dist[i] == INT_MAX) {
      cout << "INF" ;
    }
    else {
      cout << dist[i] << " ";
    }
  }
}


int main() {
  std::cout << "Hello World!\n";
}