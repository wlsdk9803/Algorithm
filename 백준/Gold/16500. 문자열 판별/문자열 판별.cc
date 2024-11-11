#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	int N; cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	vector<bool> DP(str.length() + 1);
	DP[0] = true;
	for (int i = 0; i < str.length(); i++) {
		if (!DP[i]) continue;
		for (int j = i + 1; j <= str.length(); j++) {
			if (find(v.begin(), v.end(), str.substr(i, j - i)) != v.end()) DP[j] = true;
		}
	}
	cout << DP[str.length()] ? 1 : 0;
	return 0;
}