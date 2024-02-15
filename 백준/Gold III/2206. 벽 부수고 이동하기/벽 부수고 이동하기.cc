#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define intmax INT_MAX

using namespace std;

int N, M;
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

bool isValid(int row, int col) {
	return row >= 0 && row < N && col >= 0 && col < M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>> dist(N, vector<int>(M, intmax));
	vector<vector<int>> board(N, vector<int>(M));
	vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2))); //마지막이 0이면 안부순거, 1이면 부순거
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char num; cin >> num;
			board[i][j] = num - '0';
		}
	}
	queue<pair<int, pair<int, int>>> q;
	q.push({ true, {0, 0} });
	visited[0][0][0] = true; dist[0][0] = 1;
	while (!q.empty()) {
		bool flag = q.front().first;
		int row = q.front().second.first;
		int col = q.front().second.second;
		q.pop();
		if (row == N - 1 && col == M - 1) break;
		for (int i = 0; i < 4; i++) {
			int next_row = row + dy[i];
			int next_col = col + dx[i];
			if (isValid(next_row, next_col)) {
				if (board[next_row][next_col]) { //다음 지점이 벽일 때
					if (!visited[next_row][next_col][0] && flag) { //아직 벽을 부수지 않았을 때
						visited[next_row][next_col][1] = true;
						dist[next_row][next_col] = dist[row][col] + 1;
						q.push({ false, {next_row, next_col} });
					}
				}
				if (!board[next_row][next_col]) { //다음 지점이 벽이 아닐 때
					if (!visited[next_row][next_col][0] && flag) { //아직 벽을 부수지 않았을 때
						visited[next_row][next_col][0] = true;
						dist[next_row][next_col] = dist[row][col] + 1;
						q.push({ true, {next_row, next_col} });
					}
					else if (!visited[next_row][next_col][1] && !flag) { //벽을 부순 상태일 때
						visited[next_row][next_col][1] = true;
						dist[next_row][next_col] = dist[row][col] + 1;
						q.push({ false, {next_row, next_col} });
					}
				}
			}
		}
	}
	if (dist[N - 1][M - 1] == intmax) cout << -1;
	else cout << dist[N - 1][M - 1];
	return 0;
}