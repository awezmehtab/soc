#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Dgraph {
    public:
    vector<vector<ll>> adj, adjD;
    vector<bool> can, canD;

    void input() {
        ll n, m;
        cin >> n >> m;
        adj.resize(n);
        adjD.resize(n);
        for (ll i=0; i<m; ++i) {
            ll a,b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adjD[b].push_back(a);
        }
        can.resize(n, false);
        canD.resize(n, false);
    }

    void dfs(ll u) {
        can[u] = true;
        for (ll v: adj[u]) {
            if (!can[v]) {
                dfs(v);
            }
        }
    }

    void Ddfs(ll u) {
        canD[u] = true;
        for (ll v: adjD[u]) {
            if (!canD[v]) {
                Ddfs(v);
            }
        }
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Dgraph G;
    G.input();
    G.dfs(0);
    G.Ddfs(0);

    for (ll i=0; i<(ll)G.adj.size(); ++i) {
        if (!G.can[i]) {
            cout << "NO\n";
            cout << 1 << " " << i+1 << "\n";
            return 0;
        }

        else if (!G.canD[i]) {
            cout << "NO\n";
            cout << i+1 << " " << 1 << "\n";
            return 0;
        }
    }
    cout << "YES\n";
}