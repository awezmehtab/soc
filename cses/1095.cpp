#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a, ll b, ll mod) {
    a%=mod;
    b%=mod-1;
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    for (ll i=0; i<n; ++i) {
        ll a, b;
        cin >> a >> b;
        ll MOD = 1e9+7;
        cout << power(a, b, MOD) << "\n";
    }
}