#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int row, int col) {
	return row >= 0 && row < n && col >= 0 && col < m;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			v[i][j] = c - '0';
		}
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -v[0][0], {0, 0} });
	visited[0][0] = true;
	while (!pq.empty()) {
		int cur = -pq.top().first;
		int cur_row = pq.top().second.first;
		int cur_col = pq.top().second.second; pq.pop();
		if (cur_row == n - 1 && cur_col == m - 1) {
			cout << cur;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dy[i];
			int next_col = cur_col + dx[i];
			if (isValid(next_row, next_col) && !visited[next_row][next_col]) {
				int next = cur + v[next_row][next_col];
				pq.push({ -next, {next_row, next_col} });
				visited[next_row][next_col] = true;
			}
		}
	}
	return 0;
}