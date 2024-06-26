#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> diophantine(ll a, ll b, ll c) {
    vector<ll> ans(2), pans(2);
    ll g = __gcd(a, b);
    if (c % g != 0) {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    a /= g;
    b /= g;
    c /= g;
    ans[0] = 1;
    ans[1] = -a/b;
    pans[0] = 0;
    pans[1] = 1;
    while(a*ans[0] + b*ans[1] != 1) {
        vector<ll> temp = ans;
        ans[0] = pans[0] - ((pans[0]*a + pans[1]*b)/(ans[0]*a + ans[1]*b))*ans[0];
        ans[1] = pans[1] - ((pans[0]*a + pans[1]*b)/(temp[0]*a + temp[1]*b))*ans[1];
    }
    ans[0] *= c;
    ans[1] *= c;
    return ans;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> ans = diophantine(a, b, c);
    cout << ans[0] << " " << ans[1] << endl;
}