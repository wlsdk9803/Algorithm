#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	vector<bool> visited(100001);
	vector<int> dist(100001, 1 << 30);
	vector<int> before_node(100001);
	queue<int> q;
	q.push(N);
	visited[N] = true;
	dist[N] = 0;
	vector<int> res_path;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int next = 0;
		if (cur == K) {
			cout << dist[cur] << "\n";
			res_path.push_back(cur);
			int prev = before_node[cur];
			if (cur == N) break;
			while (true) {
				res_path.push_back(prev);
				if (prev == N) break;
				prev = before_node[prev];
			}
			break;
		}
		for (int i = 0; i < 3; i++) {
			if (i == 0) next = cur - 1;
			else if (i == 1) next = cur + 1;
			else next = 2 * cur;
			if (next >= 0 && next <= 100000 && !visited[next]) {
				if (dist[cur] + 1 < dist[next]) {
					q.push(next);
					visited[next] = true;
					dist[next] = dist[cur] + 1;
					before_node[next] = cur;
				}
			}
		}
	}
	for (int i = res_path.size() - 1; i >= 0; i--) cout << res_path[i] << " ";
	return 0;
}
