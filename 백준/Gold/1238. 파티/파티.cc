#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> edge; //도착지, 비용

int dijkstra(int i, bool isGo) {
	priority_queue<pair<int, int>> pq; //-비용, 노드
	vector<int> dist(N + 1, 1 << 31 - 1);
	if (isGo) {
		pq.push({ 0, i }); dist[i] = 0;
	}
	else {
		pq.push({ 0, X }); dist[X] = 0;
	}
	while (!pq.empty()) {
		int cur = pq.top().second;
		int start_to_cur = -pq.top().first;
		pq.pop();
		if (isGo && cur == X) return start_to_cur;
		if (!isGo && cur == i) return start_to_cur;
		for (int j = 0; j < edge[cur].size(); j++) {
			int next = edge[cur][j].first;
			int cur_to_next = edge[cur][j].second;
			int start_to_next = start_to_cur + cur_to_next;
			if (dist[next] > start_to_next) {
				dist[next] = start_to_next;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> X;
	edge.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v, w; cin >> u >> v >> w;
		edge[u].push_back({ v, w });
	}
	int max_time = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		int time = (dijkstra(i, true) + dijkstra(i, false));
		max_time = max_time < time ? time : max_time;
	}
	cout << max_time;
	return 0;
}