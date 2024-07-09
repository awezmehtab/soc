#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<ll, vector<ll>> adjl;

void ask_subtree_sum(vector<ll>& tv, vector<ll>& sv,
                     vector<ll>& nv, unordered_map<ll, ll>& iv) {
    ll query; cin >> query;
    ll index = iv[query], sum=0;
    for (ll i=index; i<index+sv[index]; ++i) {
        sum += nv[i];
    }
    cout << sum << "\n";
}

vector<ll> traversal_array(adjl& adj, ll root) {
    vector<ll> v;
    v.push_back(root);
    for (auto u : adj[root]) {
        vector<ll> temp = traversal_array(adj, u);
        v.insert(v.end(), temp.begin(), temp.end());
    }
    return v;
}

unordered_map<ll, ll> subtree_sizes(adjl& adj, ll root) {
    unordered_map<ll, ll> sizes; sizes[root] = 1;
    if (adj[root].size() == 0) {
        sizes[root] = 1;
        return sizes;
    }
    for (auto u : adj[root]) {
        unordered_map<ll, ll> temp = subtree_sizes(adj, u);
        sizes[root] += temp[u];
        for (auto v : temp) {
            sizes[v.first] = v.second;
        }
    }
    return sizes;
}

int main () {
    adjl adj = {
        {1, {2, 3, 4, 5}},
        {2, {6}},
        {3, {}},
        {4, {7,8,9}},
        {5, {}},
        {6, {}},
        {7, {}},
        {8, {}},
        {9, {}}
    };
    vector<ll> tv = traversal_array(adj, 1), sv(tv.size()), nv(tv.size()), ps(tv.size());
    unordered_map<ll, ll> sizes = subtree_sizes(adj, 1), iv;
    unordered_map<ll, ll> node_values = {
        {1,4}, {2,5}, {3,3}, {4,5}, {5,2}, {6,3}, {7,5}, {8,3}, {9,1}
    };

    
    for (ll i=0; i<(ll)tv.size(); ++i) {
        sv[i] = sizes[tv[i]];
        nv[i] = node_values[tv[i]];
        iv[tv[i]] = i;
    }

    ps = nv;
    for (ll i=0; i<(ll)tv.size(); ++i) {
        for (ll j=i+1; j<i+(ll)sv[i]; ++j) {
            ps[j] += nv[i];
        }
    }

    for (auto x : tv) cout << x << " ";
    cout << "\n";
    for (auto x : sv) cout << x << " ";
    cout << "\n";
    for (auto x : nv) cout << x << " ";
    cout << "\n";
    for (auto x : ps) cout << x << " ";
    cout << "\n";
}