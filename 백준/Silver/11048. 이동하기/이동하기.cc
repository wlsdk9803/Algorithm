#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}
	vector<vector<int>> dp = v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 && j == 0) continue;
			if (i == 0 && j > 0) dp[i][j] += dp[i][j - 1];
			else if (j == 0) dp[i][j] += dp[i - 1][j];
			else dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[N - 1][M - 1];
	return 0;
}