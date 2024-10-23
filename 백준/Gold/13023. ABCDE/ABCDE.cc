#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited;
vector<vector<int>> edge;
bool is_exist = false;

void dfs(int node, int depth) {
	if (depth == 4) {
		is_exist = true; return;
	}
	visited[node] = true;
	for (int next : edge[node]) {
		if (!visited[next]) {
			dfs(next, depth + 1);
			if (is_exist) return;
		}
	}
	visited[node] = false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	edge.resize(N);
	visited.resize(N);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		dfs(i, 0);
		if (is_exist) break;
	}
	if (is_exist) cout << 1;
	else cout << 0;
	return 0;
}