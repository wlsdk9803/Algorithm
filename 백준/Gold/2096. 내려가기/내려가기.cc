#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> max_v, min_v;
	for (int i = 0; i < 3; i++) {
		int num; cin >> num;
		max_v.push_back(num);
		min_v.push_back(num);
	}
	for (int i = 1; i < n; i++) {
		vector<int> max_temp, min_temp;
		for (int j = 0; j < 3; j++) {
			int num; cin >> num;
			switch (j) {
			case 0:
				max_temp.push_back(max(max_v[0], max_v[1]) + num);
				min_temp.push_back(min(min_v[0], min_v[1]) + num);
				break;
			case 1:
				max_temp.push_back(max(max(max_v[0], max_v[1]), max_v[2]) + num);
				min_temp.push_back(min(min(min_v[0], min_v[1]), min_v[2]) + num);
				break;
			case 2:
				max_temp.push_back(max(max_v[1], max_v[2]) + num);
				min_temp.push_back(min(min_v[1], min_v[2]) + num);
				break;
			}
		}
		max_v = max_temp;
		min_v = min_temp;
	}
	sort(max_v.begin(), max_v.end());
	sort(min_v.begin(), min_v.end());
	cout << max_v[2] << " " << min_v[0];
	return 0;
}