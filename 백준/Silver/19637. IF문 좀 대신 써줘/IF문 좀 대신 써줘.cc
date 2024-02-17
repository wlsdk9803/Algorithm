#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	unordered_map<int, string> um;
	vector<int> v;
	int prev = -1;
	for (int i = 0; i < N; i++) {
		string str; int num;
		cin >> str >> num;
		if (num != prev) {
			um.insert({ num, str });
			v.push_back(num);
		}
	}
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
		cout << um[v[idx]] << "\n";
	}
	return 0;
}