#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		unordered_map<char, bool> um;
		string str; cin >> str;
		char prev = str[0];
		um.insert({ prev, true });
		if (str.length() == 1) cnt++;
		for (int i = 1; i < str.length(); i++) {
			if (prev != str[i] && um.find(str[i]) != um.end()) break;
			if (i == str.length() - 1) cnt++;
			else {
				if (prev == str[i]) continue;
				else um.insert({ str[i], true });
				prev = str[i];
			}
		}
	}
	cout << cnt;
	return 0;
}