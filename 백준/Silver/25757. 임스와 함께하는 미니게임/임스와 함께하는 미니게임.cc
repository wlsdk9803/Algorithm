#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	char game; cin >> game;
	unordered_map<string, int> um;
	vector<string> v;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		if (um.find(name) != um.end()) continue;
		um.insert({ name, 1 });
		v.push_back(name);
		switch (game) {
		case 'Y':
			if (v.size() == 1) {
				sum++;
				v.clear();
			}
			break;
		case 'F':
			if (v.size() == 2) {
				sum++;
				v.clear();
			}
			break;
		case 'O':
			if (v.size() == 3) {
				sum++;
				v.clear();
			}
			break;
		}
	}
	cout << sum;
	return 0;
}