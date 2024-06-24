#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> v(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		v[b].push_back(a);
	}
	vector<int> count(N + 1);
	int max_cnt = 0;
	for (int i = 1; i <= N; i++) {
		vector<bool> visited(N + 1);
		queue<int> q;
		q.push(i);
		visited[i] = true;
		int cnt = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int j = 0; j < v[cur].size(); j++) {
				int next = v[cur][j];
				if (!visited[next]) {
					q.push(next);
					visited[next] = true;
					cnt++;
				}
			}
		}
		count[i] = cnt;
		max_cnt = cnt > max_cnt ? cnt : max_cnt;
	}
	for (int i = 1; i <= N; i++) {
		if (count[i] == max_cnt) cout << i << " ";
	}
	return 0;
}