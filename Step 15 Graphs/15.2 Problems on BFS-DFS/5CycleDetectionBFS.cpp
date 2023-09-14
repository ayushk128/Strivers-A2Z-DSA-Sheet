#include<bits/stdc++.h>
using namespace std;
bool isCycle(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjNodes : adj[node]) {
            if(!vis[adjNodes]) {
                vis[adjNodes] = 1;
                q.push({adjNodes, node});
            }
            else if(parent != adjNodes) {
                return true;
            }
        }
    }
    return false;
}
bool CycleDetectionBFS(int n, vector<int> adj[]) {
    int vis[n] = {0};
    for(int i = 0; i<n; i++) {
        if(!vis[i]) {
            if(isCycle(i, adj, vis)) return true;
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

    if(CycleDetectionBFS(n, adj))
        cout << "Cycle" << endl;
    else 
        cout << "No Cycle" << endl;
}