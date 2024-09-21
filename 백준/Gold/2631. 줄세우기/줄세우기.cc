#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> D;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (D.empty() || D.back() < num) D.push_back(num);
		else {
			int idx = lower_bound(D.begin(), D.end(), num) - D.begin();
			D[idx] = min(num, D[idx]);
		}
	}
	cout << N - D.size();
	return 0;
}