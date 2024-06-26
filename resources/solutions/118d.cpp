/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 16 11:49:00 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 100000000

using TupleKey = std::tuple<int, int, int, int>;

map<TupleKey, int> dp;

int getOrDefault(const std::map<TupleKey, int>& m, const TupleKey& key) {
    auto it = m.find(key);
    if (it != m.end()) {
        return it->second;
    } 
    return -1;
}

int d(int n1, int n2, int k1, int k2, int last, int curr1, int curr2, int cont) {
    if (curr1 > n1 && curr2 > n2) return 0;
    if (last == 0 && cont > k1) return 0;
    if (last == 1 && cont > k2) return 0;
    TupleKey t = make_tuple(last, curr1, curr2, cont);
    int ans = getOrDefault(dp, t);
    if (ans != -1) return ans%MOD;
    if (curr1 == n1 && curr2 == n2) return dp[t] = 1;
    if (curr1 >= n1) {
        if (last == 0) return dp[t] = d(n1, n2, k1, k2, 1, curr1, curr2+1, 1)%MOD;
        return dp[t] = d(n1, n2, k1, k2, 1, curr1, curr2+1, cont+1)%MOD;
    }
    if (curr2 >= n2) {
        if (last == 1) return dp[t] = d(n1, n2, k1, k2, 0, curr1+1, curr2, 1)%MOD;
        return dp[t] = d(n1, n2, k1, k2, 0, curr1+1, curr2, cont+1)%MOD;
    }
    if (last == 0) {
        return dp[t] = (d(n1, n2, k1, k2, 0, curr1+1, curr2, cont+1) + d(n1, n2, k1, k2, 1, curr1, curr2+1, 1))%MOD;
    }
    return dp[t] = (d(n1, n2, k1, k2, 1, curr1, curr2+1, cont+1) + d(n1, n2, k1, k2, 0, curr1+1, curr2, 1))%MOD;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    cout << d(n1, n2, k1, k2, -1, 0, 0, 0) << "\n";
}
