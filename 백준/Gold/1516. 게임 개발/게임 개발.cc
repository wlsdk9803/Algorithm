#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	unordered_map<int, int> time;
	unordered_map<int, int> res;
	unordered_map<int, int> degree;
	vector<vector<int>> edge(n + 1);
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		time[i] = t;
		while (true) {
			int p; cin >> p;
			if (p == -1) break;
			edge[p].push_back(i);
			degree[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
			res[i] = time[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			res[next] = max(res[next], res[cur] + time[next]);
			degree[next]--;
			if (degree[next] == 0) q.push(next);
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << "\n";
	return 0;
}