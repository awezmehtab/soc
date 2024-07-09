#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph{
    public:
    vector<vector<ll>> adj;
    ll white=0, black=0;
    vector<ll> color;

    void input() {
        ll n; cin >> n;
        adj.resize(n);
        for (ll i=0; i<n-1; ++i) {
            ll u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        color.resize(n, -1);
    }

    void dfs(ll u, ll c) {
        color[u] = c;
        if (c==0) white++;
        else black++;
        for (ll v: adj[u]) {
            if (color[v]==-1) {
                dfs(v, 1-c);
            }
        }
    }

    void compute() {
        dfs(0, 0);
        ll n = adj.size();
        cout << white*black - (n-1) << endl;
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    graph g;
    g.input();
    g.compute();
}