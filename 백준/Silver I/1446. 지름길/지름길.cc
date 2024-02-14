#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, D; cin >> N >> D;
	vector<vector<pair<int, int>>> path(10001); // 도착점, 거리
	vector<int> edge{ 0, D };
	for (int i = 0; i < N; i++) {
		int u, v, w; cin >> u >> v >> w;
		if (v - u > w) { // 지름길이 정말 지름길인 경우에만
			path[u].push_back({ v, w });
			if (find(edge.begin(), edge.end(), u) == edge.end()) edge.push_back(u);
			if (find(edge.begin(), edge.end(), v) == edge.end()) edge.push_back(v);
		}
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size() - 1; i++) {
		for (int j = i + 1; j < edge.size(); j++) {
			path[edge[i]].push_back({ edge[j], edge[j] - edge[i] });
		}
	}
	vector<int> dist(10001, 1 << 31 - 1);
	priority_queue<pair<int, int>> pq; //-거리, 노드
	pq.push({ 0, 0 }); dist[0] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int start_to_cur = -pq.top().first;
		pq.pop();
		if (cur == D) break;
		for (int i = 0; i < path[cur].size(); i++) {
			int next = path[cur][i].first;
			int cur_to_next = path[cur][i].second;
			int start_to_next = start_to_cur + cur_to_next;
			if (dist[next] > start_to_next) {
				dist[next] = start_to_next;
				pq.push({ -dist[next], next });
			}
		}
	}
	cout << dist[D];
	return 0;
}