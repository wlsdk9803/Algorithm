#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int> degree(N + 1);
	vector<vector<int>> edge(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		degree[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			if (--degree[next] == 0) q.push(next);
		}
	}
	return 0;
}