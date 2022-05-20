#include <iostream>
using namespace std;
#include<bits/stdc++.h>

vector<vector<int>> adj;  // adjacency list representation
int p; // number of nodes
int n; // source vertex



queue<int> q;
vector<bool> used(p);
vector<int> d(p), p(p);

void bfs() {
q.push(n);
used[n] = true;
p[n] = -1;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}

if(!used[u]) {
    cout << "No path!";
} else {
    vector<int> path;
    for (int v = u; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
}
  }


int main() {
  
}