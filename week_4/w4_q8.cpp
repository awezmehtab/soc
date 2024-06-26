#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll num=1, s=1, p=1;
    for (ll i=0; i<n; ++i) {
        ll a, k;
        cin >> a >> k;
        num = (num*(k+1))%MOD;
        ll powers_of_a = 1, temp_sum=0, temp_prod=1;
        // sum is *=(1+a+a^2+...+a^k)
        // prod is *=(1*a*...*a^k)
        for (ll j=0; j<=k; ++j) {
            temp_sum = (temp_sum+powers_of_a)%MOD;
            temp_prod = (temp_prod*powers_of_a)%MOD;
            powers_of_a = (powers_of_a*(a%MOD))%MOD;
        }
        s = (s*temp_sum)%MOD;
        p = (p*temp_prod)%MOD;
        cout << "temp_sum: " << temp_sum << " temp_prod: " << temp_prod << "\n";
    }
    cout << num << " " << s << " " << p << "\n";
}