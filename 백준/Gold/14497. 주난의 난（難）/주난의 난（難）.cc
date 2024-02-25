#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int row, int col) {
	return row >= 0 && row < N && col >= 0 && col < M;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<char>> map(N, vector<char>(M));
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> map[i][j];
	}
	int count = 0;
	vector<vector<bool>> visited(N, vector<bool>(M));
	queue<pair<int, int>> q;
	q.push({ x1 - 1, y1 - 1 });
	visited[x1 - 1][y1 - 1] = true;
	while (true) {
		queue<pair<int, int>> q_temp;
		while (!q.empty()) {
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			if (row == x2 - 1 && col == y2 - 1) {
				cout << count;
				return 0;
			}
			for (int i = 0; i < 4; i++) {
				int next_row = row + dy[i];
				int next_col = col + dx[i];
				if (isValid(next_row, next_col) && !visited[next_row][next_col]) {
					visited[next_row][next_col] = true;
					if (map[next_row][next_col] == '0') q.push({ next_row, next_col });
					else {
						map[next_row][next_col] = '0';
						q_temp.push({ next_row, next_col });
					}
				}
			}
		}
		q = q_temp;
		count++;
	}
	return 0;
}