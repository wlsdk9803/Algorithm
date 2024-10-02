#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		int k; cin >> k;
		if (k == 0) break;
		vector<int> v(k), temp(k);
		for (int i = 0; i < k; i++) {
			cin >> v[i];
			if (i < 6) temp[i] = 1;
		}
		do {
			for (int i = 0; i < k; i++) {
				if (temp[i]) cout << v[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(temp.begin(), temp.end()));
		cout << "\n";
	}
	return 0;
}