#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {
    public:
    unordered_map<ll, vector<ll>> adj;
    unordered_map<ll, ll> color;

    void input () {
        ll n, m;
        cin >> n >> m;
        for (ll i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (ll i = 1; i <= n; i++) {
            color[i] = 0;
        }
    }

    bool bfs (ll u) {
        color[u] = 1;
        queue<ll> q;
        q.push(u);
        while (!q.empty()) {
            ll f = q.front(); q.pop();
            for (auto node : adj[f]) {
                if (color[node] == 0) {
                    color[node] = color[f] == 1 ? 2 : 1;
                    q.push(node);
                }
                else if (color[node] == color[f]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    graph g;
    g.input();

    for (ll i=1; i <= (ll)g.adj.size(); i++) {
        if (g.color[i] == 0) {
            bool res = g.bfs(i);
            if (!res) {
                cout << "IMPOSSIBLE" << "\n";
                return 0;
            }
        }
    }
    for (ll i = 1; i <= (ll)g.adj.size(); i++) {
        cout << g.color[i] << " ";
    }
    cout << "\n";
}