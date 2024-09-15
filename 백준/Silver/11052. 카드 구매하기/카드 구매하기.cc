#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> P(N + 1);
	vector<vector<int>> DP(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) cin >> P[i];
	for (int i = 1; i <= N; i++) DP[1][i] = i * P[1];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (j < i) DP[i][j] = DP[i - 1][j];
			else DP[i][j] = max(DP[i - 1][j], DP[i][j - i] + P[i]);
		}
	}
	cout << DP[N][N];
	return 0;
}