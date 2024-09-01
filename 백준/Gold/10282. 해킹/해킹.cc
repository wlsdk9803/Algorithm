#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int n, d, c; cin >> n >> d >> c;
		vector<vector<pair<int, int>>> edge(n + 1);
		for (int i = 0; i < d; i++) {
			int a, b, s; cin >> a >> b >> s;
			edge[b].push_back({ a, s });
		}
		vector<int> time(n + 1, INT_MAX);
		priority_queue<pair<int, int>> pq; // -시간, 노드
		pq.push({ 0, c });
		time[c] = 0;
		while (!pq.empty()) {
			int cur = pq.top().second;
			int start_to_cur = -pq.top().first; pq.pop();
			for (int i = 0; i < edge[cur].size(); i++) {
				int next = edge[cur][i].first;
				int cur_to_next = edge[cur][i].second;
				if (time[next] > start_to_cur + cur_to_next) {
					time[next] = start_to_cur + cur_to_next;
					pq.push({ -time[next], next });
				}
			}
		}
		int computer_num = 0, total_time = 0;
		for (int t : time) {
			if (t < INT_MAX) {
				computer_num++;
				total_time = max(total_time, t);
			}
		}
		cout << computer_num << " " << total_time << "\n";
	}
	return 0;
}