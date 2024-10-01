#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, res = 0;
vector<int> cols;

bool isAvailable(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (cols[i] == col || cols[i] - i == col - row || cols[i] + i == col + row) return false;
	}
	return true;
}

void dfs(int row) {
	if (row == N) {
		res++; return;
	}
	for (int col = 0; col < N; col++) {
		if (isAvailable(row, col)) {
			cols[row] = col;
			dfs(row + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cols.push_back(-1);
	dfs(0);
	cout << res;
	return 0;
}