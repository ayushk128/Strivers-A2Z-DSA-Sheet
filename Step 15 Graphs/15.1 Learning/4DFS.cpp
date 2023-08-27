#include<bits/stdc++.h>
using namespace std;
void DFSUtil(int node, vector<int> adj[], vector<int> &dfs, vector<int> &vis) {
    vis[node] = 1;
    dfs.push_back(node);

    for(auto nodes : adj[node]) {
        if(!vis[nodes]) {
            DFSUtil(nodes, adj, dfs, vis);
        }
    }
}
vector<int> DFS(int n, vector<int> adj[]) {
    vector<int> dfs;
    vector<int> vis(n + 1, 0);

    DFSUtil(1, adj, dfs, vis);
    return dfs;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for(int i = 0; i<m; i++) {
        int u, v;

        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfs = DFS(n, adj);

    for(int i = 0; i<dfs.size(); i++) {
        cout << dfs[i] << " ";
    }
}