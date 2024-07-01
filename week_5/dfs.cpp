#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> dfs(vector<bool>& visited, vector<vector<ll>>& adj, ll x) {
	vector<ll> ans; ans.push_back(x);
	visited[x] = true;
	for (auto i : adj[x]) {
		if (!visited[i]) {
			vector<ll> sub_ans = dfs(visited, adj, i);
			ans.insert(ans.end(), sub_ans.begin(), sub_ans.end());
		}
	}
	return ans;
}

bool connected(vector<bool>& visited, vector<vector<ll>>& adj) {
	bool connected = true;
	for (ll i=0; i<(ll)adj.size(); i++) {
		if((ll)dfs(visited, adj, i).size() != (ll)adj.size()) {
			connected = false;
			break;
		}
		visited.assign((ll)adj.size(), false);
	}
	return connected;
}

bool contains_cycle(vector<bool>& visited, vector<vector<ll>>& adj, ll x, ll parent) {
	visited[x] = true;
	for (auto i : adj[x]) {
		if (!visited[i]) {
			if (contains_cycle(visited, adj, i, x)) return true;
		} else if (i != parent) return true;
	}
	return false;
}

bool is_bipartite(vector<ll>& color, vector<bool>& visited,
					 vector<vector<ll>>& adj, ll x, ll c) {
	visited[x] = true;
	color[x] = c;
	for (auto i : adj[x]) {
		if (!visited[i]) {
			if (!is_bipartite(color, visited, adj, i, c^1)) return false;
		} else if (color[i] == color[x]) return false;
	}
	return true;
}


int main() {
	ll n = 5;
	vector<vector<ll>> adj(n);
	adj = {
		{2, 3},
		{4, 2},
		{0, 1, 3, 4},
		{0, 2},
		{1, 2}
	};
	vector<bool> visited(n, false);
	vector<ll> color(n);
	if (is_bipartite(color, visited, adj, 0, 0)) cout << "bipartite\n";
	else cout << "not bipartite\n";
}