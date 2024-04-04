#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<char> aeiou{ 'a','e','i','o','u' };
	while (true) {
		string str; cin >> str;
		if (str == "end") break;
		bool result = true;
		int vowel = 0, cons = 0;
		char prev = 'X'; //패스워드가 될 수 없는 글자 아무거나
		bool isinvowel = false;
		for (int i = 0; i < str.length(); i++) {
			if (find(aeiou.begin(), aeiou.end(), str[i]) != aeiou.end()) { //모음일 경우
				vowel++; cons = 0;
				isinvowel = true;
			}
			else {
				cons++; vowel = 0;
			}
			if (vowel >= 3 || cons >= 3) {
				result = false; break;
			}
			if (i > 0 && (str[i] != 'e' && str[i] != 'o') && str[i] == prev) {
				result = false; break;
			}
			prev = str[i];
		}
		if (!isinvowel) result = false;
		if (!result) cout << "<" << str << ">" << " is " << "not " << "acceptable.\n";
		else cout << "<" << str << ">" << " is " << "acceptable.\n";
	}
	return 0;
}