#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<long long> v(n);
	unordered_map<long long, int> um;
	int zero_count = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] == 0) zero_count++;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(v[i] + v[j] <= 1000000000)) um[v[i] + v[j]]++;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (um.find(v[i]) == um.end()) continue;
		int count = um[v[i]] - zero_count;
		if (v[i] == 0) count++;
		if (count > 0) res++;
	}
	cout << res;
	return 0;
}