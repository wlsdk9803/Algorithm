#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	const int max_cost = 5000001;
	vector<vector<pair<LL, LL>>> edge(N + 1);
	vector<LL> dist(N + 1, max_cost);
	for (int i = 0; i < M; i++) {
		bool flag = false;
		LL a, b, c; cin >> a >> b >> c;
		for (int j = 0; j < edge[a].size(); j++) {
			if (edge[a][j].first == b) {
				edge[a][j].second = min(edge[a][j].second, c);
				flag = true;  break;
			}
		}
		if(!flag) edge[a].push_back({ b,c });
	}
	dist[1] = 0;
	for (int k = 0; k < N - 1; k++) {
		for (int i = 1; i <= N; i++) {
			int cur = i;
			for (int j = 0; j < edge[cur].size(); j++) {
				int next = edge[i][j].first;
				LL cur_to_next = edge[i][j].second;
				if (dist[cur] != max_cost && dist[next] > dist[cur] + cur_to_next) dist[next] = dist[cur] + cur_to_next;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int cur = i;
		for (int j = 0; j < edge[cur].size(); j++) {
			int next = edge[i][j].first;
			LL cur_to_next = edge[i][j].second;
			if (dist[cur] != max_cost && dist[next] > dist[cur] + cur_to_next) {
				cout << -1;
				return 0;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (dist[i] == max_cost) cout << -1 << "\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}