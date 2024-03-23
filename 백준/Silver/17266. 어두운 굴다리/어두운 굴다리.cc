#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int prev = 0, max_dist = 0;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (i == 0) max_dist = x - prev;
		else max_dist = max((int)(ceil((double)(x - prev) / 2)), max_dist);
		prev = x;
	}
	max_dist = max(n - prev, max_dist);
	cout << max_dist;
	return 0;
}