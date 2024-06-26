#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, vector<ll>> coprimes(ll n) {
    vector<ll> s(n-1);
    for(ll i = 0; i < n-1; i++) {
        s[i] = 1;
    }
    for(ll i=2; i*i<=n; i++) {
        if(s[i-1] == 1 && !(n%i)) {
            for(ll j = i; j < n; j+=i) {
                s[j-1] = 0;
            }
        }
    }
    // for(ll i=0; i<n-1; i++) {
    //     cout << s[i] << " ";
    // }
    // cout << "\n";
    vector<ll> ans;
    ll ans_size=0;
    for(ll i=0; i<n; i++) {
        if(s[i] == 1) {
            // we'll remove x such that x*xmodn = 1
            if(((i+1)*(i+1))%n == 1 && i) {
                continue;
            }
            ans.push_back(i+1);
            ans_size++;
        }
    }
    return make_pair(ans_size, ans);
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    pair<ll, vector<ll>> ans = coprimes(n);
    cout << ans.first << "\n";
    for (ll i = 0; i < ans.first; i++) {
        cout << ans.second[i] << " ";
    }
    cout << "\n";
}