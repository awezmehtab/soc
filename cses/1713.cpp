#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX=1e6;
vector<ll> NUMS(MAX, 0);
vector<ll> PRIMES;

void compute() {
    for (ll i=2; i<=MAX; ++i) {
        if (NUMS[i] == 0) {
            PRIMES.push_back(i);
            for (ll j=2*i; j<=MAX; j+=i) {
                NUMS[j] = i;
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    compute();
    ll t;
    cin >> t;
    for (ll i=0; i<t; ++i) {
        ll n;
        cin >> n;
        ll num = 1;
        for (auto i: PRIMES) {
            if (i > n) break;
            if (n%i == 0) {
                ll cnt = 0;
                while (n%i == 0) {
                    n /= i;
                    ++cnt;
                }
                num *= (cnt+1);
            }
        }
        cout << num << "\n";
    }
}