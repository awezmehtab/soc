#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {
    public:
    ll n;
    vector<vector<ll>> adj;
    vector<ll> firstMax, secondMax, child1, child2;

    void input () {
        cin >> n;
        adj.resize(n);
        for (ll i = 0; i < n-1; i++) {
            ll a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        firstMax.resize(n, 0);
        secondMax.resize(n, 0);
        child1.resize(n, -1);
        child2.resize(n, -1);
    }

    void dfs1 (ll u, ll p) {
        for (ll v: adj[u]) {
            if (v==p) continue;
            dfs1(v, u);
            if (firstMax[v]+1 > firstMax[u]) {
                secondMax[u] = firstMax[u];
                firstMax[u] = firstMax[v]+1;
                child1[u] = v;
            } else if (firstMax[v]+1 > secondMax[u]) {
                secondMax[u] = firstMax[v]+1;
                child2[u] = v;
            }
        }
    }

    void dfs2 (ll u, ll p) {
        for (ll v: adj[u]) {
            if (v==p) continue;
            ll flp = firstMax[u], slp = secondMax[u];
        }
    }
};