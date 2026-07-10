#include <iostream>
#include <vector>
 
using namespace std;
 
vector<vector<int>> graph;
vector<int> path;
vector<bool> visited;
int target;
bool found = false;
 
void dfs(int v) {
    if (found) return;
    
    visited[v] = true;
    path.push_back(v);
    
    if (v == target) {
        found = true;
        return;
    }
    
    for (int to : graph[v]) {
        if (!visited[to]) {
            dfs(to);
            if (found) return;
        }
    }
    
    path.pop_back();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, u, v;
    cin >> n >> m >> u >> v;
    
    graph.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    visited.assign(n + 1, false);
    target = v;
    
    dfs(u);
    
    if (!found) {
        cout << "-1\n";
    } else {
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
