#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    for(ll k=1; k<=n; k++) {
        ll ans=0;
        for (ll i=1; i<=k; i++) {
            ans += i*(k/i);
        }
        cout << k << " : " << k*k-ans << endl;
    }
}