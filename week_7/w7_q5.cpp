#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    string s;
    ll pos;
    cin >> s >> pos;
    pos--; // Convert to 0-based index

    ll n = s.length();
    vector<ll> length_prefix(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        length_prefix[i] = length_prefix[i - 1] + i;
    }

    ll current_length = length_prefix[n];
    ll current_pos = pos;

    for (ll i = 0; i < n; ++i) {
        if (current_pos < length_prefix[n - i]) {
            ll remaining_length = n - i;
            for (ll j = 0; j < remaining_length; ++j) {
                if (current_pos < j + 1) {
                    cout << s[j];
                    return;
                }
                current_pos -= (j + 1);
            }
        } else {
            current_pos -= length_prefix[n - i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    cout << "\n";
    return 0;
}