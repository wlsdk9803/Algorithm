#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isValid(int row, int col, int n) {
	return row >= 0 && row < n && col >= 0 && col < n;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> map[i][j];
	}
	int res = 0;
	stack<pair<int, pair<int, int>>> s; //상태(가로면 -1, 세로면 0, 대각선이면 1), 끝점 좌표
	s.push({ -1, { 0, 1 } });
	while (!s.empty()) {
		int status = s.top().first;
		int row = s.top().second.first;
		int col = s.top().second.second;
		s.pop();
		if (row == n - 1 && col == n - 1) {
			res++; continue;
		}
		switch (status) {
		case -1:
			for (int i = 0; i < 2; i++) {
				if (i == 0) {
					int next_row = row;
					int next_col = col + 1;
					if (isValid(next_row, next_col, n) && map[next_row][next_col] == 0) s.push({ -1, {next_row, next_col} });
				}
				else {
					int next_row = row + 1;
					int next_col = col + 1;
					if(isValid(next_row, next_col, n) && map[next_row][next_col] == 0 && map[next_row - 1][next_col] == 0 && map[next_row][next_col - 1] == 0) s.push({ 1, {next_row, next_col} });
				}
			}
			break;
		case 0:
			for (int i = 0; i < 2; i++) {
				if (i == 0) {
					int next_row = row + 1;
					int next_col = col;
					if (isValid(next_row, next_col, n) && map[next_row][next_col] == 0) s.push({ 0, {next_row, next_col} });
				}
				else {
					int next_row = row + 1;
					int next_col = col + 1;
					if (isValid(next_row, next_col, n) && map[next_row][next_col] == 0 && map[next_row - 1][next_col] == 0 && map[next_row][next_col - 1] == 0) s.push({ 1, {next_row, next_col} });
				}
			}
			break;
		case 1:
			for (int i = 0; i < 3; i++) {
				if (i == 0) {
					int next_row = row;
					int next_col = col + 1;
					if (isValid(next_row, next_col, n) && map[next_row][next_col] == 0) s.push({ -1, {next_row, next_col} });
				}
				else if (i == 1) {
					int next_row = row + 1;
					int next_col = col;
					if (isValid(next_row, next_col, n) && map[next_row][next_col] == 0) s.push({ 0, {next_row, next_col} });
				}
				else {
					int next_row = row + 1;
					int next_col = col + 1;
					if (isValid(next_row, next_col, n) && map[next_row][next_col] == 0 && map[next_row - 1][next_col] == 0 && map[next_row][next_col - 1] == 0) s.push({ 1, {next_row, next_col} });
				}
			}
			break;
		}
	}
	cout << res;
	return 0;
}