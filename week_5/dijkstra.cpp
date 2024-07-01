#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e10;

vector<ll> dijkstra(vector<vector<pair<ll, ll>>>& adj, ll x) {
    ll n = adj.size();
    vector<bool> visited(n);
    vector<ll> dist(n, INF);
    dist[x] = 0;
    // will represent {-distance, node}
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, x});
    while(!q.empty()) {
        ll a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto u : adj[a]) {
            ll b = u.first, w = u.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({dist[b], b});
            }
        }
    }
    return dist;
}

int main () {
    ll n=5;
    vector<vector<pair<ll, ll>>> adj(n);
    adj = {
        {{1,5}, {3,9}, {4,1}},
        {{0, 5}, {2, 2}},
        {{1, 2}, {3, 6}},
        {{0, 9}, {2, 6}, {4, 2}},
        {{0, 1}, {3, 2}}
    };
    vector<ll> dist = dijkstra(adj, 0);
    for (int i = 0; i < n; i++) {
        cout << i << " " << dist[i] << endl;
    }
}