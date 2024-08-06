#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<vector<bool>> DP(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		DP[i][i] = true;
		if (i < n - 1 && v[i] == v[i + 1]) {
			DP[i][i + 1] = true;
			DP[i + 1][i] = true;
		}
	}
	for (int gap = 2; gap < n; gap++) {
		for (int i = 0; i + gap < n; i++) {
			int j = i + gap;
			if (v[i] == v[j] && DP[i + 1][j - 1]) DP[i][j] = true;
			DP[j][i] = DP[i][j];
		}
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << DP[a - 1][b - 1] << "\n";
	}
    return 0;
}