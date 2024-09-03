#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int N, K; cin >> N >> K;
		vector<int> time(N + 1);
		vector<vector<int>> edge(N + 1);
		vector<vector<int>> edge_before(N + 1);
		vector<int> degree(N + 1);
		for (int i = 1; i <= N; i++) cin >> time[i];
		for (int i = 0; i < K; i++) {
			int x, y; cin >> x >> y;
			edge[x].push_back(y);
			edge_before[y].push_back(x);
			degree[y]++;
		}
		int W; cin >> W;
		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (degree[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			int max_before_time = 0;
			for (int i = 0; i < edge_before[cur].size(); i++) {
				int before = edge_before[cur][i];
				max_before_time = max(max_before_time, time[before]);
			}
			time[cur] += max_before_time;
			if (cur == W) {
				cout << time[cur] << "\n";
				break;
			}
			for (int i = 0; i < edge[cur].size(); i++) {
				int next = edge[cur][i];
				if (--degree[next] == 0) q.push(next);
			}
		}
	}
	return 0;
}