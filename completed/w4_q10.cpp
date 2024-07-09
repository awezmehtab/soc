#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1e7;
vector<vector<ll>> v(MAXN + 1, vector<ll>());

void compute() {
    for (ll i = 2; i<=MAXN; ++i) {
        if(v[i].empty()) {
            for (ll j = i; j<=MAXN; j+=i){
                if(v[j].size()<2) v[j].push_back(i);
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    compute();
    ll n;
    cin >> n;
    vector<ll> first, second;
    for (ll i=0; i<n; ++i) {
        ll a;
        cin >> a;
        if(v[a].size() == 2) {
            first.push_back(v[a][0]);
            second.push_back(v[a][1]);
        } else {
            first.push_back(-1);
            second.push_back(-1);
        }
    }
    for (ll i=0; i<n; ++i) {
        cout << first[i] << " ";
    }
    cout << "\n";
    for (ll i=0; i<n; ++i) {
        cout << second[i] << " ";
    }
    cout << "\n";
}