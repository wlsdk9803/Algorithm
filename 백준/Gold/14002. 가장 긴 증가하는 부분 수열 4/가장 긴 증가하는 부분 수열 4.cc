#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> v(N + 1);
	vector<int> sub(1);
	vector<int> idx(1);
	for (int i = 1; i <= N; i++) cin >> v[i];
	for (int i = 1; i <= N; i++) {
		if (sub.back() < v[i]) sub.push_back(v[i]);
		int index = lower_bound(sub.begin(), sub.end(), v[i]) - sub.begin();
		if (v[i] < sub[index]) sub[index] = v[i];
		idx.push_back(index);
	}
	vector<int> temp;
	int n = sub.size() - 1;
	cout << n << "\n";
	for (int i = idx.size() - 1; i > 0; i--) {
		if (idx[i] == n) {
			temp.push_back(v[i]);
			n--;
		}
	}
	for (int i = temp.size() - 1; i >= 0; i--) cout << temp[i] << " ";
    return 0;
}