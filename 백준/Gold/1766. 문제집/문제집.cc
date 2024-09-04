#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> edge(N + 1);
	vector<int> degree(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		degree[b]++;
	}
	priority_queue<int> pq;
	for (int i = 1; i <= N; i++) {
		sort(edge[i].begin(), edge[i].end());
		if (degree[i] == 0) pq.push(-i);
	}
	while (!pq.empty()) {
		int cur = -pq.top(); pq.pop();
		cout << cur << " ";
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			if (--degree[next] == 0) pq.push(-next);
		}
	}
	return 0;
}