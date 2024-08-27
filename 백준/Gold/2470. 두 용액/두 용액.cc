#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<long long> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int left = 0, right = N - 1;
	int left_val = v[left], right_val = v[right];
	long long min_sum = LLONG_MAX;
	while (left < right) {
		int temp_sum = v[left] + v[right];
		if (abs(temp_sum) < abs(min_sum)) {
			min_sum = temp_sum;
			left_val = v[left];
			right_val = v[right];
		}
		if (temp_sum > 0) right--;
		else if (temp_sum < 0) left++;
		else break;
	}
	cout << left_val << " " << right_val;
	return 0;
}