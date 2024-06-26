#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> get_divisors(ll n) {
    ll i=2, j;
    while(n%i){
        ++i;
        if(i*i>=n) return make_pair(-1, -1);
    }
    j = i+1;
    while(__gcd(i+j, n)!=1 || n%j){
        ++j;
        if(j>=n) return make_pair(-1, -1);
    }
    if(j>=n) return make_pair(-1, -1);
    return make_pair(i, j);
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    vector<ll> firsts, seconds;
    for(ll i=0; i<t; i++) {
        ll n;
        cin >> n;
        pair<ll, ll> divisors = get_divisors(n);
        firsts.push_back(divisors.first);
        seconds.push_back(divisors.second);
    }
    for(ll i=0; i<t; i++) {
        cout << firsts[i] << " ";
    }
    cout << "\n";
    for(ll i=0; i<t; i++) {
        cout << seconds[i] << " ";
    }
    cout << "\n";
}