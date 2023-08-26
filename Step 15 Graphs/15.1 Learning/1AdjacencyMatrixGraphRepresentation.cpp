// Adjacency Matrix representation
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
    cout << "Empty initialization: " << endl;
    int adj[n + 1][n + 1] = {0};
    for(int i = 0; i<=n; i++) {
        for(int j = 0; j <= n; j++) {
            adj[i][j] = 0;
        }
    }


    for(int i = 0; i<=n; i++) {
        for(int j = 0; j <= n; j++) {
            cout << adj[i][j] <<" ";
        }
        cout << "\n";
    }

    // Storing edges
    for(int i = 0; i<m; i++) {
        int u, v;

        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    cout << "After Storing graph: " << endl;
    for(int i = 0; i<=n; i++) {
        for(int j = 0; j <= n; j++) {
            cout << adj[i][j] <<" ";
        }
        cout << "\n";
    }

}