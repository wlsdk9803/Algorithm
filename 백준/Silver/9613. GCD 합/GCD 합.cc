#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b % a == 0) return a;
	else return gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;;
	for (int test = 0; test < T; test++) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		long long sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) sum += gcd(v[i], v[j]);
		}
		cout << sum << "\n";
	}
    return 0;
}