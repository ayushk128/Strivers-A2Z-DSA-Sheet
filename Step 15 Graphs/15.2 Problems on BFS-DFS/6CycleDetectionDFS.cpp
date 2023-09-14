#include<bits/stdc++.h>
using namespace std;
bool isCycle(int src, int parent, vector<int> adj[], vector<int> &vis) {
    vis[src] = 1;
    for(auto adjNodes : adj[src]) {
        if(!vis[adjNodes]) {
            if(isCycle(adjNodes, src, adj, vis)) return true;
        }
        else if(adjNodes != parent) return true;
    }

    return false;
}
bool CycleDetectionDFS(int n, vector<int> adj[]) {
    vector<int> vis(n, 0);

    for(int i = 0; i<n; i++) {
        if(!vis[i]) {
            if(isCycle(i, -1, adj, vis)) return true;
        }
    }
    return false;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int m;
    cin >> n >> m;

    vector<int> adj[n];

    for(int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(CycleDetectionDFS(n, adj))
        cout << "Cycle" << endl;
    else 
        cout << "No Cycle" << endl;
}