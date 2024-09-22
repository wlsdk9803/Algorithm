#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<vector<int>> edge(N + 1);
	vector<vector<int>> edge_reverse(N + 1);
	vector<int> degree(N + 1);
	vector<int> time(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> time[i];
		int M; cin >> M;
		for (int j = 0; j < M; j++) {
			int node; cin >> node;
			edge[node].push_back(i);
			edge_reverse[i].push_back(node);
			degree[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) q.push(i);
	}
	int res = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		res = max(time[cur], res);
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			if (--degree[next] == 0) {
				int max_prev = 0;
				for (int j = 0; j < edge_reverse[next].size(); j++) {
					max_prev = max(time[edge_reverse[next][j]], max_prev);
				}
				time[next] += max_prev;
				q.push(next);
			}
		}
	}
	cout << res;
	return 0;
}