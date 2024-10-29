#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int n; cin >> n;
		vector<int> init_order(n);
		vector<int> degree(n + 1);
		vector<vector<bool>> adj(n + 1, vector<bool>(n + 1));
		for (int i = 0; i < n; i++) cin >> init_order[i];
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int a = init_order[i], b = init_order[j];
				adj[a][b] = true;
				degree[b]++;
			}
		}
		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			if (adj[a][b]) {
				adj[a][b] = false; adj[b][a] = true;
				degree[b]--; degree[a]++;
			}
			else {
				adj[b][a] = false; adj[a][b] = true;
				degree[a]--; degree[b]++;
			}
		}
		vector<int> order;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (degree[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			order.push_back(cur);
			for (int i = 1; i <= n; i++) {
				if (adj[cur][i] && --degree[i] == 0) q.push(i);
			}
		}
		if (order.size() == n) {
			for (int team : order) cout << team << " ";
			cout << "\n";
		}
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}