#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int left_idx = 0, right_idx = v.size() - 1;
	int left = v[left_idx], right = v[right_idx];
	long long min_abs_sum = abs(left + right);
	while (left_idx < right_idx) {
		long long temp_sum = v[left_idx] + v[right_idx];
		if (abs(temp_sum) < min_abs_sum) {
			min_abs_sum = abs(temp_sum);
			left = v[left_idx];
			right = v[right_idx];
		}
		if (temp_sum < 0) left_idx++;
		else right_idx--;
	}
	cout << left << " " << right;
    return 0;
}