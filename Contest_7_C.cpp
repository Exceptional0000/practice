#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
struct Edge {
    int to;
    long long weight;
};
 
struct DSU {
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};
 
struct GraphEdge {
    int u, v;
    long long w;
    
    bool operator<(const GraphEdge& other) const {
        return w > other.w;  
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, s;
    cin >> n >> m >> s;
    
    vector<GraphEdge> edges(m);
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    vector<vector<Edge>> mst(n + 1);
    
    for (const GraphEdge& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst[e.u].push_back({e.v, e.w});
            mst[e.v].push_back({e.u, e.w});
        }
    }
    
    vector<long long> ans(n + 1, 0);
    queue<int> q;
    vector<bool> visited(n + 1, false);
    
    ans[s] = -1;
    visited[s] = true;
    q.push(s);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (const Edge& e : mst[u]) {
            if (!visited[e.to]) {
                if (u == s) {
                    ans[e.to] = e.weight;
                } else {
                    ans[e.to] = min(ans[u], e.weight);
                }
                visited[e.to] = true;
                q.push(e.to);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    
    return 0;
}
