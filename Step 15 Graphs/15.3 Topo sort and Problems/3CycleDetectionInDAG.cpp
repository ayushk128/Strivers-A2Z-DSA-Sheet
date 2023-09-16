// Find topological sorting using BFS
#include<bits/stdc++.h>
using namespace std;
int TopologicalSorting(int V, vector<int> adj[]) {
    int cnt = 0;
    vector<int> indegree(V, 0);
    for(int i = 0; i<V; i++) {
        for(auto nodes : adj[i]) {
            indegree[nodes]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<indegree.size(); i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cnt++;

        for(auto nodes : adj[node]) {
            indegree[nodes]--;
            if(indegree[nodes] == 0) {
                q.push(nodes);
            }
        }
    }
    return cnt;

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

    int cnt = TopologicalSorting(V, adj);
    if(cnt != V) {
        cout << "Cyclic" <<endl;
    }
    else {
        cout << "Non Cyclic" << endl;
    }

}