#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int M, N;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
vector<vector<int>> v, DP;

bool isValid(int row, int col) {
	return row >= 0 && row < M && col >= 0 && col < N;
}

int dfs(int row, int col) {
	if (row == M - 1 && col == N - 1) return 1;
	if (DP[row][col] != -1) return DP[row][col];
	DP[row][col] = 0;
	for (int i = 0; i < 4; i++) {
		int nrow = row + dy[i];
		int ncol = col + dx[i];
		if (isValid(nrow, ncol) && v[nrow][ncol] < v[row][col]) {
			DP[row][col] += dfs(nrow, ncol);
		}
	}
	return DP[row][col];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	v.resize(M); DP.resize(M);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int num; cin >> num;
			v[i].push_back(num);
			DP[i].push_back(-1);
		}
	}
	cout << dfs(0, 0);
	return 0;
}