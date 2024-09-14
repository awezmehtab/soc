#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    vector<pair<ll, ll>> events;
    for (ll i=0; i<n; ++i) {
	ll s, e; cin >> s >> e;
	events.push_back({s, e});
    }
    sort(events.begin(), events.end(), comp);
    ll i=1, count=1, lastend=events[0].second;
    while (i<n) {
	while(events[i].first < lastend) {
	    i++;
	    if (i>=n) break;
	}
	if (i>=n) break;
	count++;
	lastend = events[i].second;
    }
    cout << count << "\n";
}
