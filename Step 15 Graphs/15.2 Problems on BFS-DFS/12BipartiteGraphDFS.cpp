#include<bits/stdc++.h>
using namespace std;
bool dfs(int src, vector<int> adj[], vector<int> &col, int iniCol) {
    col[src] = iniCol;
    for(auto nodes : adj[src]) {
        if(col[nodes] == -1) {
            if(dfs(nodes, adj, col, !iniCol) == false) return false;
        }
        else if(col[nodes] == col[src]) return false;
    }
    return true;
}
bool isBipartite(int n, vector<int> adj[]) {
    vector<int> col(n + 1, -1);

    if(dfs(1, adj, col, 0)) return true;
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
        adj[v].push_back(u);
    }

    if(isBipartite(n, adj)) {
        cout <<"Bipartite"<<endl;
    }
    else {
        cout << "Not Bipartite" << endl;
    }
}