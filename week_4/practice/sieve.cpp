#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> sieve(ll n) {
    vector<ll> s(n-1, 0);
    for (ll i=2; i<=n; i++) {
        if (s[i-2] == 0) {
            for (ll j=2; i*j<=n; j++) {
                s[i*j-2] = i;
            }
        }
    }
    return s;
}

int main() {
    ll x = 12;
    vector<ll> s = sieve(x);
    for (ll i=2; i<=x; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i: s) {
        cout << i << " ";
    }
    cout << endl;
}