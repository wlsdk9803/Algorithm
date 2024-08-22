#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int max_val = 1000001;
	int n; cin >> n;
	vector<vector<int>> rgb(n, vector<int>(3));
	int res = max_val;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) cin >> rgb[i][j];
	}
	for (int i = 0; i < 3; i++) {
		vector<int> v = rgb[0];
		for (int j = 1; j < n; j++) {
			vector<int> temp = rgb[j];
			if (j == 1) {
				if (i == 0) temp = { max_val, temp[1] + v[0], temp[2] + v[0] };
				else if (i == 1) temp = { temp[0] + v[1], max_val, temp[2] + v[1] };
				else temp = { temp[0] + v[2], temp[1] + v[2], max_val };
			}
			else if (j == n - 1) {
				if (i == 0) temp = { max_val, min(v[0], v[2]) + temp[1], min(v[0], v[1]) + temp[2] };
				else if (i == 1) temp = { min(v[1], v[2]) + temp[0], max_val, min(v[0], v[1]) + temp[2] };
				else temp = { min(v[1], v[2]) + temp[0], min(v[0], v[2]) + temp[1], max_val };
				res = min(res, min(min(temp[0], temp[1]), temp[2]));
			}
			else {
				temp[0] += min(v[1], v[2]);
				temp[1] += min(v[0], v[2]);
				temp[2] += min(v[0], v[1]);
			}
			v = temp;
		}
	}
	cout << res;
	return 0;
}