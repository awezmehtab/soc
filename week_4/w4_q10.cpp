#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1e7;
ll MAXC = -1;
vector<vector<ll>> v;

void compute(ll n) {
    if (n>MAXC) {
        MAXC = n;
        v.resize(MAXC+1);
    }
    for (ll i = 2; i<=n; ++i) {
        if(v[i].empty()) {
            for (ll j = i; j<=n; j+=i){
                if(v[j].size()<2) v[j].push_back(i);
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> first, second;
    for (ll i=0; i<n; ++i) {
        ll a, f1=-1, f2=-1;
        cin >> a;
        for (ll j=2; j*j<=a; j++) {
            if (a%j==0) {
                f1 = j;
                break;
            }
        }
        // cout << "f1: " << f1 << "\n";
        if (f1==-1) {
            first.push_back(-1);
            second.push_back(-1);
            continue;
        }
        for (ll j=f1+1; j<=a; j++) {
            // cout << "j: " << j << "\n";
            if (a%j==0 && j%f1!=0) {
                f2 = j;
                break;
            }
        }
        // cout << "f2: " << f2 << "\n";
        if (f2==-1) {
            first.push_back(-1);
            second.push_back(-1);
            continue;
        }
        first.push_back(f1);
        second.push_back(f2);
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