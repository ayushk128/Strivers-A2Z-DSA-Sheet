#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(int n, vector<int> adj[]) {
    vector<int> bfs;

    queue<int> q;
    vector<int> vis(n + 1, 0);
    for(int i = 0; i<vis.size(); i++) {
        cout << vis[i] << " ";
    }
    cout << endl;

    vis[1] = 1;
    q.push(1);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        bfs.push_back(node);
        // cout <<"Node: " << node;

        for(auto nodes : adj[node]) {
            if(!vis[nodes]) {
                vis[nodes] = 1;
                q.push(nodes);
            }
        }
    }
    return bfs;
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

    vector<int> bfs = BFS(n, adj);

    for(int i = 0; i<bfs.size(); i++) {
        cout << bfs[i] << " ";
    }
}