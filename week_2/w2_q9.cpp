#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, k; cin >> n >> k;
    vector<ll> v(n, 0);
    for (ll i = 0; i < n; i++) cin >> v[i];
    auto first = v.begin();
    ll prevresult = 0, mini=-INF, maxi=INF;
    for (ll i=0; i<n-k+1; ++i) {
	if (i>0) {
	    if (v[i-1] == v[i+k-1]) {
		cout << prevresult << " ";
		continue;
	    }
	}
	vector<ll> v_copy(first+i, first+i+k);
	nth_element(v_copy.begin(), v_copy.begin()+k/2, v_copy.end());
	if(k%2==0) {
	    vector<ll> v_copy2(first+i, first+i+k);
	    nth_element(v_copy2.begin(), v_copy2.begin()+k/2-1, v_copy2.end());
	    cout << min(v_copy[k/2], v_copy2[k/2-1])<< " ";
	    prevresult = min(v_copy[k/2], v_copy2[k/2-1]);
	    continue;
	}
	prevresult = v_copy[k/2];
	cout << v_copy[k/2] << " ";
    }
    cout << "\n";
}
