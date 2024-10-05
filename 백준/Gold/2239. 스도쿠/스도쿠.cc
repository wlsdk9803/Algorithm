#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v(9, vector<int>(9));
vector<vector<bool>> row_used(9, vector<bool>(10));
vector<vector<bool>> col_used(9, vector<bool>(10));
vector<vector<bool>> mini_used(9, vector<bool>(10));

bool col_valid(int col) {
	vector<bool> visited(10);
	for (int i = 0; i < 9; i++) {
		int num = v[i][col];
		if (num == 0) continue;
		if (!visited[num]) visited[num] = true;
		else return false;
	}
	return true;
}
bool row_valid(int row) {
	vector<bool> visited(10);
	for (int i = 0; i < 9; i++) {
		int num = v[row][i];
		if (num == 0) continue;
		if (!visited[num]) visited[num] = true;
		else return false;
	}
	return true;
}
bool mini_valid(int row, int col) {
	vector<bool> visited(10);
	int srow = row - row % 3, scol = col - col % 3;
	for (int i = srow; i < srow + 3; i++) {
		for (int j = scol; j < scol + 3; j++) {
			int num = v[i][j];
			if (num == 0) continue;
			if (!visited[num]) visited[num] = true;
			else return false;
		}
	}
	return true;
}
void dfs(int row, int col) {
	if (row == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout << v[i][j];
			cout << "\n";
		}
		exit(0);
	}
	if (v[row][col] == 0) {
		for (int i = 1; i <= 9; i++) {
			int srow = row - row % 3, scol = col - col % 3;
			if (row_used[row][i] || col_used[col][i] || mini_used[srow + scol / 3][i]) continue;

			v[row][col] = i;
			row_used[row][i] = true;
			col_used[col][i] = true;
			mini_used[srow + scol / 3][i] = true;

			if (col_valid(col) && row_valid(row) && mini_valid(row, col)) {
				if (col < 8) dfs(row, col + 1);
				else dfs(row + 1, 0);
			}

			v[row][col] = 0;
			row_used[row][i] = false;
			col_used[col][i] = false;
			mini_used[srow + scol / 3][i] = false;
		}
	}
	else {
		if (col < 8) dfs(row, col + 1);
		else dfs(row + 1, 0);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char n; cin >> n;
			int num = n - '0';
			v[i][j] = num;
			if (num != 0) {
				int srow = i - i % 3, scol = j - j % 3;
				row_used[i][num] = true;
				col_used[j][num] = true;
				mini_used[srow + scol / 3][num] = true;
			}
		}
	}
	dfs(0, 0);
	return 0;
}