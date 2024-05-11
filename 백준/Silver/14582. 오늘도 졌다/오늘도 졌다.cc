#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int jm_sum = 0, sl_sum = 0;
	vector<int> v(9);
	for (int i = 0; i < 9; i++) cin >> v[i];
	for (int i = 0; i < 9; i++) {
		int sl; cin >> sl;
		jm_sum += v[i];
		if (jm_sum > sl_sum) {
			cout << "Yes";
			return 0;
		}
		sl_sum += sl;
	}
	cout << "No";
	return 0;
}