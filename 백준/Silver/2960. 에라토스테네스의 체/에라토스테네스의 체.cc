#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<bool> v(n + 1, true);
	int count = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (v[j]) {
				v[j] = false; count++;
			}
			if (count == k) {
				cout << j;
				return 0;
			}
		}
	}
	return 0;
}