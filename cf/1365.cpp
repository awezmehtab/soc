#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll R_CHANGE[]{0, 1, 0, -1};
const ll C_CHANGE[]{1, 0, -1, 0};

class graph {
    public:
    vector<vector<ll>> grid;
    ll n, m;
    vector<pair<ll, ll>> bad, good;
    vector<vector<bool>> esc, canesc;

    void input () {
        cin >> n >> m;
        grid.resize(n, vector<ll>(m));
        bad.resize(m*n), good.resize(m*n);
        for (ll i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (ll j = 0; j < m; j++) {
                grid[i][j] = s[j];
                if (s[j] == 'B') {
                    bad.push_back({i, j});
                } else if (s[j] == 'G') {
                    good.push_back({i, j});
                }
            }
        }
        canesc.resize(n, vector<bool>(m, false));
    }

    void print () {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printEsc () {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cout << esc[i][j] << " ";
            }
            cout << endl;
        }
    }

    ll canescape() {
        ll count = 0;
        for (auto i : good) {
            bool nearesc;
            for (ll j=0; j<4; ++j) {
                if (i.first + R_CHANGE[j] < 0 || i.first + R_CHANGE[j] >= n ||
                    i.second + C_CHANGE[j] < 0 || i.second + C_CHANGE[j] >= m) {
                        continue;
                    }
                if (esc[i.first + R_CHANGE[j]][i.second + C_CHANGE[j]]) {
                    nearesc = true;
                    break;
                }
            }
            if (!canesc[i.first][i.second] && nearesc) {
                canesc[i.first][i.second] = true;
                count++;
                vector<vector<bool>> new_visited(n, vector<bool>(m, false));
                new_visited[i.first][i.second] = true;
                queue<pair<ll, ll>> q;
                q.push(i);
                while(!q.empty()) {
                    pair<ll, ll> v = q.front();
                    q.pop();
                    for (ll j=0; j<4; ++j) {
                        if (v.first + R_CHANGE[j] < 0 || v.first + R_CHANGE[j] >= n ||
                            v.second + C_CHANGE[j] < 0 || v.second + C_CHANGE[j] >= m ||
                            grid[v.first + R_CHANGE[j]][v.second + C_CHANGE[j]] == '#' ||
                            grid[v.first + R_CHANGE[j]][v.second + C_CHANGE[j]] == 'B' ||
                            grid[v.first + R_CHANGE[j]][v.second + C_CHANGE[j]] == '.' ||
                            new_visited[v.first + R_CHANGE[j]][v.second + C_CHANGE[j]]) {
                                continue;
                            }
                        new_visited[v.first + R_CHANGE[j]][v.second + C_CHANGE[j]] = true;
                        canesc[v.first + R_CHANGE[j]][v.second + C_CHANGE[j]] = true;
                        q.push({v.first + R_CHANGE[j], v.second + C_CHANGE[j]});
                        count++;
                    }
                }
            }
        }
        return count;
    }

    void escfill() {
        esc.resize(n, vector<bool>(m, false));
        esc[n-1][m-1] = true;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[n-1][m-1] = true;
        queue<pair<ll, ll>> q;
        q.push({n-1,m-1});
        while(!q.empty()) {
            pair<ll, ll> v = q.front();
            q.pop();

            if (v.first < 0 || v.first >=n || v.second < 0 || v.second >= m ||
                grid[v.first][v.second] == '#' || visited[v.first][v.second]) {
                    continue;
                }
            
            visited[v.first][v.second] = true;
            esc[v.first][v.second] = true;
            for (ll i=0; i<4; ++i) {
                q.push({v.first+R_CHANGE[i], v.second + C_CHANGE[i]});
            }
        }
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t; cin >> t;
    vector<string> ans;
    for (ll t_0=0; t_0<t; ++t_0) {
        graph g;
        g.input();
        g.escfill();
        for (auto i : g.bad) {
            for (ll j = 0; j < 4; j++) {
                ll r = i.first + R_CHANGE[j];
                ll c = i.second + C_CHANGE[j];
                if (r < 0 || r >= g.n || c < 0 || c >= g.m) {
                    continue;
                }
                if (g.esc[r][c]) {
                    g.grid[r][c] = '#';
                }
            }
        }
        cout << "Case #" << t_0+1 << ":\n";
        g.print();
        g.printEsc();
        cout << "---\n";
        g.escfill();
        if (g.esc[g.n-1][g.m-1]=='.' && g.canescape() == (ll)g.good.size()) {
            ans.push_back("Yes");
        } else {
            ans.push_back("No");
        }
    }

    for (auto i : ans) {
        cout << i << endl;
    }
}