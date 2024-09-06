#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int n; cin >> n;
		vector<vector<int>> edge(n + 1);
		vector<int> degree(n + 1);
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			edge[i].push_back(a);
			degree[a]++;
		}
		for (int i = 1; i <= n; i++) {
			if (degree[i] == 0) q.push(i);
		}
		int res = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			res++;
			for (int i = 0; i < edge[cur].size(); i++) {
				int next = edge[cur][i];
				if (--degree[next] == 0) q.push(next);
			}
		}
		cout << res << "\n";
	}
	return 0;
}