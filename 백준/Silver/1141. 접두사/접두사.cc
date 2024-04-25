#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
	if (a.first.length() != b.first.length()) {
		return a.first.length() < b.first.length();
	}
	return a.first < b.first;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<string, bool>> v(n);
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		v[i] = { str, true };
	}
	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < n; i++) {
		if (!v[i].second) continue;
		string cur = v[i].first;
		for (int j = i + 1; j < n; j++) {
			int len = cur.length();
			if (v[j].second && v[j].first.substr(0, len) == v[i].first) v[i].second = false;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second) res++;
	}
	cout << res;
	return 0;
}