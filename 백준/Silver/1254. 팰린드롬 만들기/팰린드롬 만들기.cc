#include <iostream>
#include <string>

using namespace std;

bool isPalindrom(string str) {
	bool res = true;
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - 1 - i]) {
			res = false; break;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	for (int i = 0; i < str.length(); i++) {
		string sub_string = str.substr(i);
		if (isPalindrom(sub_string)) {
			cout << str.length() + i;
			break;
		}
	}
    return 0;
}