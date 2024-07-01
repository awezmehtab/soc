#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e10;

vector<ll> bellman_ford(ll n, vector<vector<ll>>& edges, ll x) {
    vector<ll> dist(n, INF);
    dist[x] = 0;
    for (ll i=0; i<n-1; ++i) {
        for (auto edge : edges) {
            ll a = edge[0], b = edge[1], w = edge[2];
            dist[b] = min(dist[b], dist[a] + w);
        }
    }
    return dist;
}

int main () {
    ll n=5;
    vector<vector<ll>> edges;
    edges = {
        {0, 1, 5},
        {0, 2, 3},
        {0, 3, 7},
        {1, 3, 3},
        {1, 4, 2},
        {2, 3, 1},
        {3, 4, 2},
    };
    for (auto edge : edges) {
        edges.push_back({edge[1], edge[0], edge[2]});
    }
    vector<ll> dist = bellman_ford(n, edges, 0);
    for (int i = 0; i < n; i++) {
        cout << i << " " << dist[i] << endl;
    }
}