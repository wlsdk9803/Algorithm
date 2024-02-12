#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isValid(int row, int col, int N) {
	return row >= 0 && row < N && col >= 0 && col < N;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	vector<vector<pair<bool, bool>>> board(N, vector<pair<bool, bool>>(N)); // {사과 여부, 뱀이 차지하고 있는지}
	queue<pair<int, int>> snake; //뱀이 차지하고 있는 칸
	for (int i = 0; i < K; i++) {
		int row, col; cin >> row >> col;
		board[row - 1][col - 1].first = true;
	}
	int L; cin >> L;
	queue<pair<int, char>> dir; //방향 전환 정보
	for (int i = 0; i < L; i++) {
		int X; char C; cin >> X >> C;
		dir.push({ X,C });
	}

	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };
	int head_row = 0, head_col = 0;
	board[0][0].second = true; snake.push({ 0, 0 });
	int time = 0, idx = 0;
	while (true) {
		time++;
		head_row += dy[idx]; head_col += dx[idx];
		if(!isValid(head_row, head_col, N)) break;
		if (board[head_row][head_col].second) break;
		board[head_row][head_col].second = true;
		snake.push({ head_row, head_col });
		if (board[head_row][head_col].first) board[head_row][head_col].first = false; //사과 O
		else { //사과 X
			int tail_row = snake.front().first, tail_col = snake.front().second; 
			snake.pop();
			board[tail_row][tail_col].second = false;
		}
		if (!dir.empty() && time == dir.front().first) {
			if (dir.front().second == 'D') idx = (idx + 1) % 4;
			else if (dir.front().second == 'L') {
				if (idx == 0) idx = 3;
				else idx--;
			}
			dir.pop();
		}
	}
	cout << time;
	return 0;
}