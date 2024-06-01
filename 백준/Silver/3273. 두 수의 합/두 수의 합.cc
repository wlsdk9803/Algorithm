#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int x; cin >> x;

	int res = 0;
	int left = 0, right = n - 1;
	while (left < right) {
		if (v[left] + v[right] > x) right--;
		else if (v[left] + v[right] == x) {
			res++; right--;
		}
		else {
			left++;
			if (right < n - 1) right++;
		}
	}
	cout << res;
	return 0;
}