#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<vector<int>> dp(N + 1, vector<int>(10));
	for (int i = 0; i < 10; i++) dp[1][i] = 1; // i로 끝나는 한자리 오르막 수 개수
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
		}
	}
	int res = 0;
	for (int i = 0; i < 10; i++) res = (res + dp[N][i]) % 10007;
	cout << res;
	return 0;
}