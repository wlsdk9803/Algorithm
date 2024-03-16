#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int n, int row, int col) {
	return row >= 0 && row < n && col >= 0 && col < n;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int p = 1;
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		vector<vector<int>> map(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cin >> map[i][j];
		}
		vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
		priority_queue<pair<int, pair<int, int>>> pq; //-비용, 노드(row, col)
		pq.push({ -map[0][0], {0, 0} });
		while (!pq.empty()) {
			int start_to_cur = -pq.top().first;
			int cur_row = pq.top().second.first;
			int cur_col = pq.top().second.second;
			pq.pop();
			if (cur_row == n - 1 && cur_col == n - 1) break;
			for (int i = 0; i < 4; i++) {
				int next_row = cur_row + dy[i];
				int next_col = cur_col + dx[i];
				if (isValid(n, next_row, next_col)) {
					int cur_to_next = map[next_row][next_col];
					if (cost[next_row][next_col] > start_to_cur + cur_to_next) {
						cost[next_row][next_col] = start_to_cur + cur_to_next;
						pq.push({ -cost[next_row][next_col], {next_row, next_col} });
					}
				}
			}
		}
		cout << "Problem " << p << ": " << cost[n - 1][n - 1] << "\n";
		p++;
	}
	return 0;
}