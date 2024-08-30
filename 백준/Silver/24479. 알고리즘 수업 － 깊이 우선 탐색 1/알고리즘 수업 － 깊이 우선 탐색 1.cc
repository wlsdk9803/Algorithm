#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, R; cin >> N >> M >> R;
	vector<vector<int>> edge(N + 1);
	vector<bool> visited(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) sort(edge[i].begin(), edge[i].end(), greater<>());
	int order_num = 1;
	vector<int> orders(N + 1, 100002);
	stack<int> s;
	s.push(R);
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		visited[cur] = true;
		if (orders[cur] > order_num + 1) orders[cur] = order_num++;
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			if (!visited[next]) s.push(next);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (orders[i] == 100002) cout << 0 << "\n";
		else cout << orders[i] << "\n";
	}
	return 0;
}