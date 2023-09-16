#include<bits/stdc++.h>
using namespace std;
bool isBipartite(int n, vector<int> adj[]) {
    vector<int> col(n + 1, -1);

    queue<int> q;
    q.push(1);
    col[1] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto nodes : adj[node]) {
            if(col[nodes] == -1) {
                col[nodes] = !col[node];
                q.push(nodes);
            }
            else if(col[nodes] == col[node]) {
                return false;
            }
        }
    }
    return true;
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