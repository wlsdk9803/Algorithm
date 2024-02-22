#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; //n은 도시 개수, m은 버스 개수
	const int max_cost = 10000001;
	int adj[101][101];
	fill(adj[0], adj[101], max_cost);
	int dist[101][101];

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j] != max_cost) dist[i][j] = adj[i][j];
			else dist[i][j] = max_cost;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == max_cost) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}