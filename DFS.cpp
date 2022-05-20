#include <iostream>
using namespace std;
#include<bits/stdc++.h>


int n; // no of vertices
vector<vector<int>> adj;
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





int main() {
  
}