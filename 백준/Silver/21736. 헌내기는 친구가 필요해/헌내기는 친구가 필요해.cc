#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int N, M;

bool isValid(int row, int col) {
	return row >= 0 && row < N && col >= 0 && col < M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<char>> v(N, vector<char>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'I') {
				q.push({ i, j });
				visited[i][j] = true;
			}
		}
	}
	int res = 0;
	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dy[i];
			int next_col = cur_col + dx[i];
			if (isValid(next_row, next_col) && !visited[next_row][next_col] && v[next_row][next_col] != 'X') {
				q.push({ next_row, next_col });
				visited[next_row][next_col] = true;
				if (v[next_row][next_col] == 'P') res++;
			}
		}
	}
	if (res == 0) cout << "TT";
	else cout << res;
	return 0;
}