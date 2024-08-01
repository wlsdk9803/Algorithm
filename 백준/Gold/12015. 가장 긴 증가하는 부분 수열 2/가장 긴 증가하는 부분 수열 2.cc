#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> v;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (v.empty() || num > v.back()) {
			v.push_back(num);
		}
		else {
			int index = lower_bound(v.begin(), v.end(), num) - v.begin();
			v[index] = num;
		}
	}
	cout << v.size();
	return 0;
}