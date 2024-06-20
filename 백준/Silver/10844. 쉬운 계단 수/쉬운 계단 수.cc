#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int div = 1000000000;
	int N; cin >> N;
	vector<vector<long long>> DP(N + 1, vector<long long>(10));
	for (int i = 1; i <= 9; i++) DP[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		DP[i][0] = DP[i - 1][1];
		DP[i][9] = DP[i - 1][8];
		for (int j = 1; j <= 8; j++) DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % div;
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += DP[N][i] % div;
		sum %= div;
	}
	cout << sum;
	return 0;
}