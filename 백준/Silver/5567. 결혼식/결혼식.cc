#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<pair<int, int>> q;
	q.push({ 1, 0 }); // node, depth

	vector<bool> visited(n + 1);
	visited[1] = true;
	int res = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int depth = q.front().second; q.pop();
		if (depth == 2) continue;
		for (int f : v[cur]) {
			if (!visited[f]) {
				visited[f] = true;
				res++;
				q.push({ f, depth + 1 });
			}
		}
	}
	cout << res;
	return 0;
}