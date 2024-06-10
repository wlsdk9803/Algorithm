#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int max_dist = 101;
	int n; cin >> n;
	vector<vector<int>> adj(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> adj[i][j];
	}
	vector<vector<int>> dist(n, vector<int>(n, max_dist));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (adj[i][j]) dist[i][j] = adj[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == max_dist) cout << 0 << " ";
			else cout << 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}