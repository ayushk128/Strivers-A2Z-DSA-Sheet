#include<bits/stdc++.h>
using namespace std;
vector<int> ordering(int V, vector<pair<int, int>> prerequiseites) {
    vector<int> adj[V];

    for(auto it : prerequiseites) {
        adj[it.first].push_back(it.second);
    }

    vector<int> topo;
    vector<int> indegree(V, 0);

    for(int i = 0; i<V; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<indegree.size(); i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto nodes : adj[node]) {
            indegree[nodes]--;
            if(indegree[nodes] == 0) {
                q.push(nodes);
            }
        }
    }
    return topo; 
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    int M;
    cin >> M;

    vector<pair<int, int>> prerequiseites;

    for(int i = 0; i<M; i++) {
        int task1, task2;

        cin >> task1 >> task2;

        prerequiseites.push_back({task1, task2});
    }
    // cout << "Prerequisites: " << endl;
    // for(auto it : prerequiseites) {
    //     cout << it.first << " " << it.second << endl;
    // }
    vector<int> order = ordering(N, prerequiseites);

    if(order.size() != N) {
        cout << "Not Possible" << endl;
    }
    for(int i = 0; i<order.size(); i++) {
        cout << order[i] << " ";
    }
}