#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<vector<int>> v(n + 1);
	while (true) {
		int a, b; cin >> a >> b;
		if (a == -1 && b == -1) break;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int> score(n + 1);
	int min_score = 51;
	for (int i = 1; i <= n; i++) {
		vector<bool> visited(n + 1);
		vector<int> dist(n + 1, 51);
		queue<int> q;
		q.push(i);
		visited[i] = true;
		dist[i] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int next : v[cur]) {
				if (!visited[next]) {
					dist[next] = min(dist[next], dist[cur] + 1);
					score[i] = max(score[i], dist[next]);
					q.push(next);
					visited[next] = true;
				}
			}
		}
		min_score = min(min_score, score[i]);
	}
	int count = 0;
	cout << min_score << " ";
	for (int i = 1; i <= n; i++) {
		if (score[i] == min_score) count++;
	}
	cout << count << "\n";
	for (int i = 1; i <= n; i++) {
		if (score[i] == min_score) cout << i << " ";
	}
	return 0;
}