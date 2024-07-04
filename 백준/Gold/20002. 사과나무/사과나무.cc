#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long sum = -1001;
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = v[i][j];
			sum = num < sum ? sum : num;

			long long temp_sum = num;
			for (int gap = 1; gap <= min(n - i - 1, n - j - 1); gap++) {
				for (int k = 0; k <= gap; k++) temp_sum += v[i + k][j + gap];
				for (int k = 0; k < gap; k++) temp_sum += v[i + gap][j + k];
				sum = temp_sum < sum ? sum : temp_sum;
			}
		}
	}
	cout << sum;
	return 0;
}