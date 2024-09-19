#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, K; cin >> N >> M >> K;
	vector<int> v(N + 1);
	vector<vector<int>> edge(N + 1);
	vector<bool> visited(N + 1);
	for (int i = 1; i <= N; i++) cin >> v[i];
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	queue<int> q;
	vector<pair<int, int>> candies; // 인원수, 개수
	for (int i = 1; i <= N; i++) {
		int people = 0, candy = 0;
		if (!visited[i]) {
			q.push(i); visited[i] = true;
		}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			people++; candy += v[cur];
			for (int j = 0; j < edge[cur].size(); j++) {
				int next = edge[cur][j];
				if (!visited[next]) {
					q.push(next);
					visited[next] = true;
				}
			}
		}
		if(people > 0) candies.push_back({ people, candy });
	}
	vector<int> DP(K);
	for (int i = 0; i < candies.size(); i++) {
		int people = candies[i].first;
		int candy = candies[i].second;
		for (int j = K - 1; j >= people; j--) {
			DP[j] = max(DP[j], DP[j - people] + candy);
		}
	}
	cout << DP[K - 1];
	return 0;
}