#include <iostream>
#include <bits/stdc++.h>
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
int noOfPath(int src, int dest, int N , vector<vector<int>> adj) {
  vector<int> s = topoSort(N ,adj);

  int dp = {0};
  dp[dest] = 1;

  for(int i = s.size() -1 ;  i>=0; i--) {
    for(int j =0; i<  adj[s[i]].size(); j++) {
      dp[s[i]] += dp[adj[s[i][j]]];
    }
  }
  return dp;
}

int main() {
  std::cout << "Hello World!\n";
}