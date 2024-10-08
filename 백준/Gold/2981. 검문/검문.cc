#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	int x = max(a, b), y = min(a, b);
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> v(N);
	vector<int> gap;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int prev = v[0];
	for (int i = 1; i < N; i++) {
		gap.push_back(v[i] - prev);
		prev = v[i];
	}
	int total_gcd = gcd(gap[1], gap[0]);
	for (int i = 2; i < gap.size(); i++) {
		total_gcd = gcd(total_gcd, gap[i]);
	}
	vector<int> res;
	for (int i = 2; i <= total_gcd / 2; i++) {
		if (total_gcd % i == 0) res.push_back(i);
	}
	res.push_back(total_gcd);
	for (int elem : res) cout << elem << " ";
	return 0;
}