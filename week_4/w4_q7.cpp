#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 1e6;

vector<int> grundy(MAXN + 1, -1); // Initialize Grundy numbers with -1 (uncomputed)

int compute_grundy(int n) {
    if (n <= 1) return 0; // Base case

    if (grundy[n] != -1) return grundy[n];

    unordered_set<int> s;
    for (int i = 1; i <= (n&1 ? n/2 : n/2-1); ++i) {
        int g = compute_grundy(i) ^ compute_grundy(n - i);
        s.insert(g);
    }

    int mex = 0;
    while (s.count(mex)) {
        mex++;
    }

    return grundy[n] = mex; // Memoize and return the computed Grundy number
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    int max_n = 0;
    vector<int> queries(t);

    for (int i = 0; i < t; ++i) {
        cin >> queries[i];
        max_n = max(max_n, queries[i]);
    }

    // Precompute Grundy numbers up to max_n using memoization
    for (int i = 0; i <= max_n; ++i) {
        compute_grundy(i);
    }

    // Output results for each query
    for (int i = 0; i < t; ++i) {
        cout << (grundy[queries[i]] ? "first\n" : "second\n");
    }

    return 0;
}
