#include<bits/stdc++.h>
using namespace std;
void DFSUtil(int node, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;

    for(auto nodes : adj[node]) {
        if(!vis[nodes]) {
            DFSUtil(nodes, vis, adj);
        }
    }
}
int NumberOfProviencesDFS(int V, vector<int> adj[]) {
    int count = 0;
    vector<int> vis(V+1, 0);

    for(int i = 1; i<=V; i++) {
        if(!vis[i]) {
            DFSUtil(i, vis, adj);
            count++;
        }
    }
    return count;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int V, E;
    cin >> V >> E;

    vector<int> adj[V+1];
    for(int i = 0; i<E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    cout << NumberOfProviencesDFS(V, adj) << endl;
}