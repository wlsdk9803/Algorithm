#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	long long max_sum = 0;
	vector<long long> m(N);
	vector<long long> c(N);
	for (int i = 0; i < N; i++) cin >> m[i];
	for (int i = 0; i < N; i++) {
		cin >> c[i];
		max_sum += c[i];
	}
	
	vector<vector<long long>> DP(N, vector<long long>(max_sum + 1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < max_sum + 1; j++) {
			if (i == 0) {
				if (j >= c[i]) DP[i][j] = m[i];
			}
			else {
				if (j < c[i]) DP[i][j] = DP[i - 1][j];
				else DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - c[i]] + m[i]);
			}
		}
	}
	for (int j = 0; j < max_sum + 1; j++) {
		if (DP[N - 1][j] >= M) {
			cout << j; break;
		}
	}
	return 0;
}