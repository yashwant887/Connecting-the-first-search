#include <iostream>
using namespace std;
#include<bits/stdc++.h>


int n; // no of vertices
vector<vector<int>> adj; // adjacency list representation of graph
vector<bool> visited;




// DFS
vector<int> color;
vector<int> time_in,time_out;
int dfs_timer = 0;

void dfs(int v) {
  time_in[v] = dfs_timer++;
  color[v] = 1;
  for(int u : adj[v])
    if(color[u] == 0)
      dfs(u);
  color[v] = 2;
  time_out[v] = dfs_timer++;
}

void Cycle(int n, vector<bool> visited, vector<vector<int>> adj, int v){
  for(int u : dfs(v)) {
    if(!visited[u] && !dfs(u)){
    cout << " Cycle is Present" << endl;
    }
  }