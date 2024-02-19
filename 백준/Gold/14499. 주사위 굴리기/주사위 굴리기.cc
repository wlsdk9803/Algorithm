#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<vector<int>> map;
vector<int> dice(6);

bool isValid(int row, int col) {
	return row >= 0 && row < N && col >= 0 && col < M;
}
void rollright(int next_row, int next_col) {
	int temp1 = dice[0], temp3 = dice[2], temp4 = dice[3], temp6 = dice[5];
	dice[0] = temp4;
	dice[2] = temp1;
	dice[3] = temp6;
	dice[5] = temp3;
	if (map[next_row][next_col] == 0) map[next_row][next_col] = dice[5];
	else {
		dice[5] = map[next_row][next_col];
		map[next_row][next_col] = 0;
	}
}
void rollleft(int next_row, int next_col) {
	int temp1 = dice[0], temp3 = dice[2], temp4 = dice[3], temp6 = dice[5];
	dice[0] = temp3;
	dice[2] = temp6;
	dice[3] = temp1;
	dice[5] = temp4;
	if (map[next_row][next_col] == 0) map[next_row][next_col] = dice[5];
	else {
		dice[5] = map[next_row][next_col];
		map[next_row][next_col] = 0;
	}
}
void rollup(int next_row, int next_col) {
	int temp1 = dice[0], temp2 = dice[1], temp5 = dice[4], temp6 = dice[5];
	dice[0] = temp5;
	dice[1] = temp1;
	dice[4] = temp6;
	dice[5] = temp2;
	if (map[next_row][next_col] == 0) map[next_row][next_col] = dice[5];
	else {
		dice[5] = map[next_row][next_col];
		map[next_row][next_col] = 0;
	}
}
void rolldown(int next_row, int next_col) {
	int temp1 = dice[0], temp2 = dice[1], temp5 = dice[4], temp6 = dice[5];
	dice[0] = temp2;
	dice[1] = temp6;
	dice[4] = temp1;
	dice[5] = temp5;
	if (map[next_row][next_col] == 0) map[next_row][next_col] = dice[5];
	else {
		dice[5] = map[next_row][next_col];
		map[next_row][next_col] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, y, K; cin >> N >> M >> x >> y >> K;
	map.resize(N);
	for (int i = 0; i < N; i++) map[i].resize(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> map[i][j];
	}
	for (int i = 0; i < K; i++) {
		int dir; cin >> dir;
		int next_row = x + dy[dir - 1];
		int next_col = y + dx[dir - 1];
		if (!isValid(next_row, next_col)) continue;
		switch (dir) {
		case 1:
			rollright(next_row, next_col);
			break;
		case 2:
			rollleft(next_row, next_col);
			break;
		case 3:
			rollup(next_row, next_col);
			break;
		case 4:
			rolldown(next_row, next_col);
			break;
		}
		x = next_row;
		y = next_col;
		cout << dice[0] << "\n";
	}
	return 0;
}