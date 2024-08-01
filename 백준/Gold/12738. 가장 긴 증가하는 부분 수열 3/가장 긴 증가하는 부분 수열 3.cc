#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> v(N + 1);
	vector<int> sub(1, -1000000001);
	for (int i = 1; i <= N; i++) cin >> v[i];
	for (int i = 1; i <= N; i++) {
		if (sub.back() < v[i]) {
			sub.push_back(v[i]);
			continue;
		}
		int idx = lower_bound(sub.begin(), sub.end(), v[i]) - sub.begin();
		sub[idx] = min(sub[idx], v[i]);
	}
	cout << sub.size() - 1;
    return 0;
}