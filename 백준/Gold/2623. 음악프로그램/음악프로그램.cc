#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int> degree(N + 1);
	vector<vector<int>> edge(N + 1);
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		vector<int> temp(num);
		for (int j = 0; j < num; j++) cin >> temp[j];
		for (int j = 0; j < num - 1; j++) {
			edge[temp[j]].push_back(temp[j + 1]);
			degree[temp[j + 1]]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) q.push(i);
	}
	vector<int> res;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		res.push_back(cur);
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			if (--degree[next] == 0) q.push(next);
		}
	}
	if (res.size() == N) {
		for (int n : res) cout << n << "\n";
	}
	else cout << 0;
	return 0;
}