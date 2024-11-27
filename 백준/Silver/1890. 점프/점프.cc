#include <iostream>
#include <vector>

using namespace std;

bool isvalid(int row, int col, int N) {
	return row >= 0 && row < N && col >= 0 && col < N;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<vector<int>> v(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	vector<vector<long long>> dp(N, vector<long long>(N));
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == 0) continue;
			if (j + v[i][j] < N) dp[i][j + v[i][j]] += dp[i][j];
			if (i + v[i][j] < N) dp[i + v[i][j]][j] += dp[i][j];
		}
	}
	cout << dp[N - 1][N - 1];
	return 0;
}