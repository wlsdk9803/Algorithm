#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input_order;

bool comp(int a, int b) {
	return input_order[a] < input_order[b];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<vector<int>> edge(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	vector<int> inputs(N);
	input_order.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> inputs[i];
		input_order[inputs[i]] = i;
	}
	for (int i = 1; i <= N; i++) sort(edge[i].begin(), edge[i].end(), comp);
	vector<bool> visited(N + 1);
	queue<int> q;
	q.push(1); visited[1] = true;
	int index = 0;
	bool res = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur != inputs[index++]) {
			res = false; break;
		}
		for (int next : edge[cur]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
	cout << res;
	return 0;
}