#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string S, E, Q; cin >> S >> E >> Q;
	unordered_map<string, pair<bool, bool>> um;
	vector<string> v;
	string time, name;
	while (cin >> time >> name) {
		if (um.find(name) == um.end()) {
			um.insert({ name, {false, false} });
			v.push_back(name);
		}
		if (time <= S) um[name].first = 1;
		if (time >= E && time <= Q) um[name].second = 1;
	}
	int count = 0;
	for (string student : v) {
		if (um[student] == make_pair(true, true)) count++;
	}
	cout << count;
	return 0;
}