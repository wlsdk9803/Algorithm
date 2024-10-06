#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, R; cin >> N >> M >> R;
	vector<vector<int>> edge(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) sort(edge[i].begin(), edge[i].end());
	queue<int> q;
	vector<int> order(N + 1, 1 << 30);
	vector<int> visited(N + 1);
	int order_num = 1;
	q.push(R);
	order[R] = order_num++; visited[R] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			if (!visited[next]) {
				q.push(next);
				order[next] = order_num++;
				visited[next] = true;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (order[i] == 1 << 30) cout << 0 << "\n";
		else cout << order[i] << "\n";
	}
	return 0;
}