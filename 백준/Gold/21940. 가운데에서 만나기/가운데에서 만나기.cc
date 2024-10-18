#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int max_dist = 1 << 30;
	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N + 1, vector<int>(N + 1, max_dist));
	for (int i = 1; i <= N; i++) adj[i][i] = 0;
	for (int i = 0; i < M; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u][v] = min(adj[u][v], w);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (adj[i][k] < max_dist && adj[k][j] < max_dist) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	int K; cin >> K;
	vector<int> dest(K);
	for (int i = 0; i < K; i++) cin >> dest[i];

	int time = max_dist;
	for (int i = 1; i <= N; i++) {
		int temp_time = 0; bool valid = true;
		for (int node : dest) {
			if (adj[i][node] == max_dist || adj[node][i] == max_dist) {
				valid = false; break;
			}
			temp_time = max(temp_time, adj[i][node] + adj[node][i]);
		}
		if(valid) time = min(time, temp_time);
	}

	vector<int> res;
	for (int i = 1; i <= N; i++) {
		int temp_time = 0;
		for (int node : dest) {
			if (adj[i][node] != max_dist && adj[node][i] != max_dist) temp_time = max(temp_time, adj[i][node] + adj[node][i]);
		}
		if (temp_time == time) res.push_back(i);
	}
	sort(res.begin(), res.end());
	for (int node : res) cout << node << " ";
	return 0;
}