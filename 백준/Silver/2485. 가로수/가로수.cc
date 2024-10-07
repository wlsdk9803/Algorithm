#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	int max_v = max(a, b), min_v = min(a, b);
	if (min_v == 0) return max_v;
	return gcd(min_v, max_v % min_v);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> gap;
	int prev = 0;
	for (int i = 0; i < N; i++) {
		int pos; cin >> pos;
		if (i > 0) gap.push_back(pos - prev);
		prev = pos;
	}
	int total_gcd = gcd(gap[1], gap[0]);
	for (int i = 2; i < gap.size(); i++) {
		total_gcd = gcd(total_gcd, gap[i]);
	}
	int res = 0;
	for (int i = 0; i < gap.size(); i++) res += (gap[i] / total_gcd - 1);
	cout << res;
	return 0;
}