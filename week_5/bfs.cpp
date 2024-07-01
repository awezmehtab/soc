#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n=6;
    vector<vector<ll>> adj(n);
    adj = {
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0},
        {1, 5},
        {2, 4}
    };
    vector<ll> dist(n);
    vector<bool> visited(n);
    queue<ll> q;

    ll x; cin >> x;
    q.push(x);
    visited[x] = true;
    dist[x] = 0;
    while(!q.empty()) {
        ll s = q.front();
        q.pop();
        for(auto u: adj[s]) {
            if(!visited[u]) {
                visited[u] = true;
                dist[u] = dist[s] + 1;
                q.push(u);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << " " << dist[i] << endl;
    }
}