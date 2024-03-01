#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, 100001));
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) adj[i][j] = 0;
		}
	}
	vector<vector<vector<int>>> path(n + 1, vector<vector<int>>(n + 1));
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
					vector<int> buf = path[i][k];
					buf.push_back(k);
					buf.insert(buf.end(), path[k][j].begin(), path[k][j].end());
					path[i][j] = buf;
				}
				
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adj[i][j] == 100001) cout << 0 << " ";
			else cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adj[i][j] == 100001 || i == j) cout << 0 << "\n";
			else {
				cout << path[i][j].size() + 2 << " " << i << " ";
				for (int k = 0; k < path[i][j].size(); k++) cout << path[i][j][k] << " ";
				cout << j << "\n";
			}
		}
	}
	return 0;
}