#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int n; cin >> n;
		vector<string> clothes;
		unordered_map<string, int> um;
		for (int i = 0; i < n; i++) {
			string name, type; cin >> name >> type;
			if (um.find(type) == um.end()) {
				um.insert({ type, 1 });
				clothes.push_back(type);
			}
			else um[type]++;
		}
		long long res = 1;
		for (int i = 0; i < clothes.size(); i++) {
			res *= (um[clothes[i]] + 1);
		}
		cout << res - 1 << "\n";
	}
	return 0;
}