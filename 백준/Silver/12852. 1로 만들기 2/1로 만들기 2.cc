#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> dist(N + 1, 1 << 30);
	vector<int> parent(N + 1, -1);
	queue<int> q;
	q.push(N);
	dist[N] = 0; parent[1] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == 1) break;
		int next = cur;
		for (int i = 0; i < 3; i++) {
			if (i == 0 && cur % 3 == 0) next = cur / 3;
			else if (i == 1 && cur % 2 == 0) next = cur / 2;
			else if (i == 2) next = cur - 1;
			if (dist[next] > dist[cur] + 1) {
				dist[next] = dist[cur] + 1;
				parent[next] = cur;
				q.push(next);
			}
		}
	}
	cout << dist[1] << "\n";
	vector<int> temp = { 1 };
	while (true) {
		int next = parent[temp.back()];
		if(next != 1) temp.push_back(next);
		if (next == N) break;
	}
	reverse(temp.begin(), temp.end());
	for (int n : temp) cout << n << " ";
	return 0;
}