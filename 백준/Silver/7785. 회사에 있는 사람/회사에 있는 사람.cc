#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<string> temp;
	unordered_map<string, bool> um;
	for (int i = 0; i < n; i++) {
		string name, dir; cin >> name >> dir;
		if (um.find(name) == um.end()) {
			if (dir == "enter") um.insert({ name, true });
			else um.insert({ name, false });
			temp.push_back(name);
		}
		else {
			if (dir == "enter") um[name] = true;
			else um[name] = false;
		}
	}
	sort(temp.begin(), temp.end(), greater<>());
	for (int i = 0; i < temp.size(); i++) {
		if (um[temp[i]]) cout << temp[i] << "\n";
	}
	return 0;
}