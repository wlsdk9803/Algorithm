#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> edge(N + 1);
	vector<int> degree(N + 1);
	for (int i = 0; i < M; i++) {
		int A, B; cin >> A >> B;
		edge[A].push_back(B);
		degree[B]++;
	}
	vector<int> orders(N + 1, 1);
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next : edge[cur]) {
			if (--degree[next] == 0) {
				orders[next] = orders[cur] + 1;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) cout << orders[i] << " ";
	return 0;
}