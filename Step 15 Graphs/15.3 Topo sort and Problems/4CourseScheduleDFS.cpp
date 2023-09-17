#include<bits/stdc++.h>
using namespace std;
void topoSort(int src, vector<int> adj[], vector<int> &vis, stack<int> &s) {
    vis[src] = 1;
    for(auto nodes : adj[src]) {
        if(!vis[nodes]) {
            topoSort(nodes, adj, vis, s);
        }
    }
    s.push(src);
}
bool isPossible(int N, vector<pair<int, int>> prerequiseites) {
    vector<int> adj[N];
    for(auto it : prerequiseites) {
        adj[it.first].emplace_back(it.second);
    }

    cout << "Graph: " << endl;
    for(int i = 0; i<N; i++) {
        cout << i <<"-->";
        for(auto nodes : adj[i]) {
            cout << nodes << ", ";
        }
        cout << endl;
    }
    vector<int> vis(N, 0);
    stack<int> s;
    for(int i = 0; i<N; i++) {
        if(!vis[i]) {
            topoSort(i, adj, vis, s);
        }
    }

    cout <<"Stack Size: " << s.size() << endl;

    vector<int> ordering;
    while(!s.empty()) {
        int element = s.top();
        s.pop();

        ordering.emplace_back(element);
    }

    if(ordering.size() == N) return true;
    return false;    
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

    // if(isPossible(N, prerequiseites)) {
    //     cout << "Possible" << endl;
    // }
    // else {
    //     cout << "Not Possible" << endl;
    // }
}