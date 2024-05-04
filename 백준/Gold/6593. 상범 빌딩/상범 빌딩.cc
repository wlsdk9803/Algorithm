#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int dy[] = { 0, 0, 1, -1, 0, 0 };
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dh[] = { 0, 0, 0, 0, 1, -1 };
int L, R, C;

bool isValid(int row, int col, int h) {
	return row >= 0 && row < R && col >= 0 && col < C && h >= 0 && h < L;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> L >> R >> C;
		if (!L && !R && !C) break;
		vector<vector<vector<char>>> building(L, vector<vector<char>>(R, vector<char>(C)));
		vector<vector<vector<bool>>> visited(L, vector<vector<bool>>(R, vector<bool>(C)));
		vector<vector<vector<int>>> dist(L, vector<vector<int>>(R, vector<int>(C, INT_MAX)));
		queue<pair<int, pair<int, int>>> q;
		int erow = 0, ecol = 0, eh = 0;
		for (int k = 0; k < L; k++) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					cin >> building[k][i][j];
					if (building[k][i][j] == 'S') {
						q.push({ k, {i, j} });
						visited[k][i][j] = true;
						dist[k][i][j] = 0;
					}
					if (building[k][i][j] == 'E') {
						erow = i, ecol = j, eh = k;
					}
				}
			}
		}
		while (!q.empty()) {
			int cur_h = q.front().first;
			int cur_row = q.front().second.first;
			int cur_col = q.front().second.second;
			q.pop();
			if (cur_h == eh && cur_row == erow && cur_col == ecol) break;
			for (int i = 0; i < 6; i++) {
				int nh = cur_h + dh[i];
				int nrow = cur_row + dy[i];
				int ncol = cur_col + dx[i];
				if (isValid(nrow, ncol, nh) && !visited[nh][nrow][ncol] && building[nh][nrow][ncol] != '#') {
					q.push({ nh, {nrow, ncol} });
					visited[nh][nrow][ncol] = true;
					dist[nh][nrow][ncol] = min(dist[nh][nrow][ncol], dist[cur_h][cur_row][cur_col] + 1);
				}
			}
		}
		if (dist[eh][erow][ecol] == INT_MAX) cout << "Trapped!\n";
		else cout << "Escaped in " << dist[eh][erow][ecol] << " minute(s).\n";
	}
	return 0;
}
