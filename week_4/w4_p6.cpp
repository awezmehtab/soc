#include<bits/stdc++.h>
using namespace std;

typedef long double db;
typedef long long ll;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    db k;
    cin >> n >> k;
    db sum = k; // k^(n+1)/k^n
    for (db i=1; i<k; i++) {
        sum -= pow(i/k, n);
    }
    cout << fixed << setprecision(6) << sum << "\n";
}