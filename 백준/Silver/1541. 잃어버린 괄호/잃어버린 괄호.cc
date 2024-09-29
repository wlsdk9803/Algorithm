#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	int idx = 0, res = 0;
	bool isminus = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '+' && str[i] != '-' && i != str.length() - 1) continue;
		int num = i == str.length() - 1 ? stoi(str.substr(idx, i + 1 - idx)) : stoi(str.substr(idx, i - idx));
		if (isminus) res -= num;
		else res += num;
		if (str[i] == '-') isminus = true;
		idx = i + 1;
	}
	cout << res;
	return 0;
}