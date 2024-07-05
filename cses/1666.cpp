#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {
    public:
    unordered_map<ll, vector<ll>> adj;
    unordered_map<ll, ll> component, c2p;

    void inpput_with_component() {
        ll n, m;
        cin >> n >> m;
        for (ll i=0; i<m; ++i) {
            
        }
    }

    void input() {
        ll n, m;
        cin >> n >> m;
        for(ll i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (ll i = 1; i <= n; i++) {
            component[i] = 0;
        }
    }

    void dfs(ll u, ll comp) {
        component[u] = comp;
        c2p[comp] = u;
        for(auto v: adj[u]) {
            if(component[v] == 0) {
                dfs(v, comp);
            }
        }
        return;
    }
    
    // solved answer
    void solve() {
        ll comp = 0, non_zero_comp;
        for(auto i: adj) {
            if(component[i.first] == 0) {
                comp++;
                dfs(i.first, comp);
            }
        }

        non_zero_comp = comp;

        for (auto i: component) {
            if(i.second == 0) {
                comp++;
            }
        }
        cout << comp-1 << endl;
        // cout << non_zero_comp << endl;

        for(ll i=non_zero_comp-1; i>0; i--) {
            cout << c2p[non_zero_comp] << " " << c2p[i] << endl;
        }
        for (auto i: component) {
            if(i.second == 0) {
                cout << i.first << " " << c2p[non_zero_comp] << endl;
            }
        }
    }
};

int main () {
    graph g;
    g.input();
    g.solve();
}