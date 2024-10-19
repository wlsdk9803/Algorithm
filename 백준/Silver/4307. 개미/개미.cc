#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int len, n; cin >> len >> n;
		vector<int> min_v(n);
		vector<int> max_v(n);
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			int reverse_num = len - num;
			int min_num = min(num, reverse_num);
			int max_num = max(num, reverse_num);
			min_v[i] = min_num;
			max_v[i] = max_num;
		}
		sort(min_v.begin(), min_v.end());
		sort(max_v.begin(), max_v.end());
		cout << min_v[n - 1] << " " << max_v[n - 1] << "\n";
	}
	return 0;
}