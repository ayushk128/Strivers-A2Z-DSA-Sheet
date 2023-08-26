// Adjacency List representation
#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Number of nodes
    int n;

    // Number of edges
    int m;
    cin >> n >> m;

    // Graph
    vector<int> adj[n + 1];

    // Storing edges
    for(int i = 0; i<m; i++) {
        int u, v;

        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    // 1-based indexing, so starging with one
    for(int i = 1; i<=n; i++) {
        cout << i <<"-->";
        for(auto nodes : adj[i]) {
            cout << nodes << ", ";
        }
        cout << endl;
    }
}