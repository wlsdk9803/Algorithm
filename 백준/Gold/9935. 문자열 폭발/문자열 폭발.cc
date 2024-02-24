#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str, bomb; cin >> str >> bomb;
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		s.push(str[i]);
		if (s.size() >= bomb.length() && str[i] == bomb[bomb.length() - 1]) {
			string last;
			for (int j = 0; j < bomb.length(); j++) {
				last.push_back(s.top()); s.pop();
			}
			reverse(last.begin(), last.end());
			if (last != bomb) {
				for (int j = 0; j < last.length(); j++) s.push(last[j]);
			}
		}
	}
	if (s.empty()) cout << "FRULA";
	else {
		string result = "";
		while (!s.empty()) {
			result.push_back(s.top());
			s.pop();
		}
		reverse(result.begin(), result.end());
		cout << result;
	}
	return 0;
}