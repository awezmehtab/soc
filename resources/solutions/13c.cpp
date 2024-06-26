/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun  7 22:36:56 IST 2024
**/

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    vector<int> prev(n);
    vector<int> curr(n);
    prev[0] = abs(a[0]-b[0]);
    for (int i = 1 ; i < n ; i ++) prev[i] = min(abs(a[0]-b[i]), prev[i-1]);
    for (int i = 1 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
            if (j == 0) {
                curr[j] = abs(a[i]-b[0])+prev[0];
            }
            else curr[j] = min(curr[j-1], prev[j]+abs(a[i]-b[j]));
        }
        prev = curr;
    }
    cout << curr[n-1];
}
