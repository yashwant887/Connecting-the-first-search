#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void findTopoSort(int node, vector<bool>visited , queue<int> q ,vector<vector<int>> adj){
  visited[node] = true;
  for(int it : adj[node]) {
    if(!visited[i]) {
      findTopoSort(it,visited, q, adj);
    }
  }
  q.push(node);
}
class Pair{
  int v;
  int weight;
};

void longestPath(int src, int N, int u , int v,vector<vector<pair<int,int>>> adj) {
  bool visited[i] = false;
  queue<int> q;
  for(int i = 0 ; i<N ; i++) {
    if(!visited[i]) {
      findTopoSort(i, visited, q , adj);
    }
  }
  int dist[N];
  for(int i=0; i< N;i++){
    dist[i] = INT_MIN;
    dist[src] = 0;
  }
  while(!q.empty()) {
    int node = q.back();
    q.pop();
  }
  if(dist[node] != INT_MIN) {
    for( auto it : adj[node]) {
      if(dist[it.second] + dist[node] > dist[it.first]){
        dist[it.first] = dist[it.second] + dist[node] 
      }
    }
  }
  for(int i =0; i<N;i++) {
    if(dist[i] == INT_MIN) {
      cout << "NINF";
    }
    else{
      cout << dist[i] << " ";
    }
  }
}

int main() {
  std::cout << "Hello World!\n";
}