#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> mat, list;
    Graph(int v) : V(v), mat(v, vector<int>(v)), list(v) {}

    void add(int u, int v) {
        mat[u][v] = mat[v][u] = 1;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    void DFS(int s) {
        vector<bool> vis(V); stack<int> st; st.push(s);
        cout << "DFS: ";
        while (!st.empty()) {
            int u = st.top(); st.pop();
            if (vis[u]) continue;
            vis[u] = 1; cout << u << " ";
            for (int v = V; v--;) if (mat[u][v] && !vis[v]) st.push(v);
        }
        cout << '\n';
    }

    void BFS(int s) {
        vector<bool> vis(V); queue<int> q; q.push(s); vis[s] = 1;
        cout << "BFS: ";
        while (!q.empty()) {
            int u = q.front(); q.pop(); cout << u << " ";
            for (int v : list[u]) if (!vis[v]) vis[v] = 1, q.push(v);
        }
        cout << '\n';
    }
};

int main() {
    Graph g(5);
    for (auto [u, v] : vector<pair<int, int>>{{0,1},{0,2},{1,3},{2,3},{3,4}})
        g.add(u, v);
    g.DFS(0); g.BFS(0);
}
