#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long res = -1001;
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}
	vector<vector<long long>> sum(n + 1, vector<long long>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + v[i - 1][j - 1] - sum[i - 1][j - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= min(i, j); k++) {
				long long temp_sum = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
				res = res > temp_sum ? res : temp_sum;
			}
		}
	}
	cout << res;
	return 0;
}