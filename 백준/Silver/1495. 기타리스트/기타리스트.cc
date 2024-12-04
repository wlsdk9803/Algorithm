#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, S, M; cin >> N >> S >> M;
	vector<int> diff(N);
	for (int i = 0; i < N; i++) cin >> diff[i];

	vector<vector<bool>> dp(N + 1, vector<bool>(M + 1));
	dp[0][S] = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j]) {
				if (j + diff[i - 1] <= M) dp[i][j + diff[i - 1]] = true;
				if (j - diff[i - 1] >= 0) dp[i][j - diff[i - 1]] = true;
			}
		}
	}
	int res = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i]) res = max(res, i);
	}
	cout << res;
	return 0;
}