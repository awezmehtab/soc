#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {
    public:

    unordered_map<ll, vector<ll>> adj;
    unordered_map<ll, ll> watchmen;
    vector<ll> secureNodes;
    unordered_map<ll, bool> isSecure;

    graph(ll n) {
        adj.reserve(n);
    }

    void inputEdges(ll m) {
        for (ll i=0; i<m; ++i) {
            ll a_i, b_i;
            cin >> a_i >> b_i;
            adj[a_i].push_back(b_i);
            adj[b_i].push_back(a_i);
        }
    }

    void print() {
        for (auto v : adj) {
            cout << v.first << " : ";
            for (auto i : v.second) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }

    void inputWatchmen(ll k) {
        for (ll i=0; i<k; ++i) {
            ll p_i, h_i;
            cin >> p_i >> h_i;
            watchmen[p_i] = h_i;
        }
    }

    void find_secure_nodes() {
        for (auto watchman : watchmen) {
            auto [at, reach] = watchman;
            unordered_map<ll, bool> in_reach;
            queue<pair<ll, ll>> q;
            q.push({at, 0});
            in_reach[at] = true;
            while(!q.empty()) {
                auto [node, dist] = q.front();
                q.pop();
                if (!isSecure[node]) {
                    secureNodes.push_back(node);
                    isSecure[node] = true;
                }
                if (dist == reach) {
                    continue;
                }
                for (auto i : adj[node]) {
                    if (!in_reach[i]) {
                        in_reach[i] = true;
                        q.push({i, dist+1});
                    }
                }
            }
        }
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    graph g(n);
    g.inputEdges(m);
    g.inputWatchmen(k);
    
    g.find_secure_nodes();
    sort(g.secureNodes.begin(), g.secureNodes.end());
    cout << g.secureNodes.size() << "\n";
    for (auto i : g.secureNodes) {
        cout << i << " ";
    }
    cout << "\n";
}