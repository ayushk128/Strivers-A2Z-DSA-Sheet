#include<bits/stdc++.h>
using namespace std;
void TopologicalSortingUtil(int src, vector<int> adj[], vector<int> &vis, stack<int> &s) {
    vis[src] = 1;
    for(auto nodes : adj[src]) {
        if(!vis[nodes]) {
            TopologicalSortingUtil(nodes, adj, vis, s);
        }
    }
    s.push(src);
}
vector<int> TopologicalSorting(int V, vector<int> adj[]) {
    vector<int> topo;
    vector<int> vis(V, 0);
    stack<int> s;
    for(int i = 0; i<V; i++) {
        if(!vis[i]) {
            TopologicalSortingUtil(i, adj, vis, s);
        }
    }

    while(!s.empty()) {
        int ele = s.top();
        s.pop();
        topo.push_back(ele);
    }
    return topo;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for(int i = 0; i<E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> topoSort = TopologicalSorting(V, adj);
    for(int i = 0; i<topoSort.size(); i++) {
        cout << topoSort[i] << " ";
    }

}