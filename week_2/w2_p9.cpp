#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class medianfinder {
public:
    ll n, m;
    vector<ll> v;
    multiset<ll> up, low;

    medianfinder () {
	cin >> n >> m;
	v.resize(n);
	for (ll i = 0; i < n; i++) cin >> v[i];
	low.insert(v[0]);
	for (ll i = 1; i < m; i++) ins(v[i]);
	cout << *low.rbegin() << ' ';
	for (ll i = m; i < n; i++) {
	    if (m==1) {
		ins(v[i]);
		del(v[i-m]);
	    } else {
		del(v[i-m]);
		ins(v[i]);
	    }
	    cout << *low.rbegin() << ' ';
	}
	cout << '\n';
    }

    void ins (ll x) {
	ll median = *low.rbegin();
	if (x > median) {
	    up.insert(x);
	    if (up.size() > m/2) {
		low.insert(*up.begin());
		up.erase(up.find(*up.begin()));
	    }
	} else {
	    low.insert(x);
	    if (low.size() > (m+1)/2) {
		up.insert(*low.rbegin());
		low.erase(low.find(*low.rbegin()));
	    }
	}
    }

    void del (ll x) {
	if (up.find(x) != up.end()) up.erase(up.find(x));
	else low.erase(low.find(x));
	if (low.empty()) {
	    low.insert(*up.begin());
	    up.erase(up.find(*up.begin()));
	}
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    medianfinder m;
}
