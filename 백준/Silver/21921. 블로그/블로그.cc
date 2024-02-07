#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < x; i++) sum += v[i];
	int max_sum = sum;
	int count = 1;

	int left = 1, right = x + 1;
	while (right <= n) {
		sum = sum - v[left - 1] + v[right - 1];
		if (sum > max_sum) {
			max_sum = sum;
			count = 1;
		}
		else if (sum == max_sum) count++;
		left++;  right++;
	}
	if (max_sum == 0) cout << "SAD";
	else cout << max_sum << "\n" << count;
	return 0;
}