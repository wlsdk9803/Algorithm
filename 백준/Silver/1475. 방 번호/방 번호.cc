#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	unordered_map<int, int> um;
	for (int i = 0; i < str.length(); i++) {
		int num = str[i] - '0';
		if (num == 9) num = 6;
		if (um.find(num) == um.end()) um.insert({ num, 1 });
		else um[num]++;
	}
	if (um.find(6) != um.end()) {
		if (um[6] % 2 == 0) um[6] /= 2;
		else um[6] = (um[6] + 1) / 2;
	}
	int res = 0;
	for (int i = 0; i < 9; i++) res = res < um[i] ? um[i] : res;
	cout << res;
	return 0;
}