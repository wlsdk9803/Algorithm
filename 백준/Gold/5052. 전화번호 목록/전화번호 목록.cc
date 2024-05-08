#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int test = 0; test < t; test++) {
		int n; cin >> n;
		vector<string> v;
		unordered_map<string, int> um;
		bool valid = true;
		for (int i = 0; i < n; i++) {
			string str; cin >> str;
			um.insert({ str, 1 });
			v.push_back(str);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < v[i].length(); j++) {
				if (um.find(v[i].substr(0, j)) != um.end()) {
					valid = false; break;
				}
			}
			if (!valid) break;
		}
		if (!valid) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}