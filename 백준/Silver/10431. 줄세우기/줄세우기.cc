#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int P; cin >> P;
	for (int test = 0; test < P; test++) {
		int T; cin >> T;
		vector<int> v;
		int res = 0;
		for (int i = 0; i < 20; i++) {
			int num; cin >> num;
			v.push_back(num);
			if (i == 0) continue;
			for (int j = v.size() - 1; j > 0; j--) {
				if (v[j] > v[j - 1]) break;
				int temp = v[j - 1];
				v[j - 1] = v[j];
				v[j] = temp;
				res++;
			}
		}
		cout << T << " " << res << "\n";
	}
	return 0;
}