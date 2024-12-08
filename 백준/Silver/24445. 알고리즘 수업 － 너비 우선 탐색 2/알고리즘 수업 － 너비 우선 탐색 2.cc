#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
	for (int i = 1; i <= N; i++) sort(edge[i].begin(), edge[i].end(), greater<>());
	vector<int> visited(N + 1), orders(N + 1);
	queue<int> q;
	q.push(R); visited[R] = true;
	int order = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		orders[cur] = order++;
		for (int next : edge[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) cout << orders[i] << "\n";
	return 0;
}