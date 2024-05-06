#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<bool> v(n + 1);
	for (int i = 1; i < n + 1; i++) {
		bool b; cin >> b;
		v[i] = b;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int sex, num; cin >> sex >> num;
		switch (sex)
		{
		case 1:
			for (int i = num; i < n + 1; i += num) v[i] = !v[i];
			break;
		case 2:
			v[num] = !v[num];
			for (int j = 1; j <= min(num - 1, n - num); j++) {
				if (v[num - j] == v[num + j]) {
					v[num - j] = !v[num - j];
					v[num + j] = !v[num + j];
				}
				else break;
			}
			break;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		cout << v[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
	return 0;
}