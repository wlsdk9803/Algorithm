#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	reverse(v.begin(), v.end());

	vector<int> d(1);
	for (int i = 0; i < v.size(); i++) {
		if (d.back() < v[i]) {
			d.push_back(v[i]);
			continue;
		}
		int idx = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
		d[idx] = min(d[idx], v[i]);
	}
	cout << d.size() - 1;
    return 0;
}