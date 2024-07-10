#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {
    public:
    ll n, m;
    vector<vector<pair<ll, ll>>> adj;
    vector<vector<ll>> edges;
    vector<bool> visited;

    graph () {
        cin >> n >> m;
        adj.resize(n);
        for (ll i=0; i<m; ++i) {
            ll a, b, w;
            cin >> a >> b >> w;
            a--; b--;
            adj[a].push_back({b, w});
            edges.push_back({a, b, w});
        }
        visited.resize(n, false);
    }

    void bellman_ford(ll start) {
        visited[start] = true;
    }
};