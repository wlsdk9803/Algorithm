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
	vector<int> visited(N + 1), depths(N + 1, -1);
	queue<int> q;
	q.push(R); visited[R] = true; depths[R] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next : edge[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				depths[next] = depths[cur] + 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) cout << depths[i] << "\n";
	return 0;
}