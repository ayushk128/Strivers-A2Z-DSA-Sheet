#include<bits/stdc++.h>
using namespace std;
bool cycleDetectionUtil(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto nodes : adj[node]) {
        if(!vis[nodes]) {
            if(cycleDetectionUtil(nodes, adj, vis, pathVis)) return true;
        }
        else {
            if(pathVis[nodes]) return true;
        }
    }
    pathVis[node] = 0;

    return false;
}
bool cycleDetection(int V, vector<int> adj[]) {
    vector<int> vis(V+1, 0);
    vector<int> pathVis(V+1, 0);

    for(int i = 1; i<=V; i++) {
        if(!vis[i]) {
            if(cycleDetectionUtil(i, adj, vis, pathVis)) return true;
        }
    }
    return false;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int e;

    cin >> n >> e;

    vector<int> adj[n + 1];
    for(int i = 0; i<e; i++) {
        int u;
        int v;
        cin >> u >> v;

        adj[u].push_back(v);
    }
    if(cycleDetection(n, adj)) {
        cout << "Cycle" << endl;
    }
    else {
        cout << "No Cycle" << endl;
    }
}