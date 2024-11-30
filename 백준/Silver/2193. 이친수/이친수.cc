#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<vector<long long>> dp(N + 1, vector<long long>(2));
	if (N == 1 || N == 2) {
		cout << 1;
		return 0;
	}
	dp[1][1] = 1; dp[2][0] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[N][0] + dp[N][1];
	return 0;
}