#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	long long res = LLONG_MAX;
	long long cur = 0, left = 0, right = 0;
	for (int i = 0; i < n - 2; i++) {
		int left_idx = i + 1, right_idx = n - 1;
		while (left_idx < right_idx) {
			long long temp_sum = v[i] + v[left_idx] + v[right_idx];
			if (abs(temp_sum) < res) {
				res = abs(temp_sum);
				cur = v[i];
				left = v[left_idx];
				right = v[right_idx];
			}
			if (temp_sum < 0) left_idx++;
			else right_idx--;
		}
	}
	cout << cur << " " << left << " " << right;
    return 0;
}