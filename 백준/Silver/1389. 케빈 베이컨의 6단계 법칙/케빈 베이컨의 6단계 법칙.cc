#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, 200000000));
	vector<vector<int>> dist(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i == j) continue;
			else dist[i][j] = adj[i][j];
		}
	}
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	pair<int, int> res = { 0, 200000000 };
	for (int i = 1; i < n + 1; i++) {
		int kevin = 0;
		for (int j = 1; j < n + 1; j++) kevin += dist[i][j];
		if (res.second > kevin) res = { i, kevin };
		else if (res.second == kevin) res = { min(res.first, i), kevin };
	}
	cout << res.first;
	return 0;
}