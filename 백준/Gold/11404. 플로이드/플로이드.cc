#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, 10000001));
	vector<vector<int>> dist(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u][v] = min(adj[u][v], w);
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
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (dist[i][j] == 10000001) dist[i][j] = 0;
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
