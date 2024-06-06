#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> v(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int> dist(N + 1, INT_MAX);
	vector<bool> visited(N + 1);
	queue<int> q;
	q.push(1); dist[1] = 0; visited[1] = true;
	int max_dist = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				dist[next] = min(dist[next], dist[cur] + 1);
				max_dist = max(max_dist, dist[next]);
			}
		}
	}
	bool isfirst = true;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == max_dist) {
			if (isfirst) {
				cout << i << " " << dist[i] << " ";
				isfirst = false;
			}
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}