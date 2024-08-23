#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		string str; getline(cin, str);
		if (str == ".") break;
		stack<char> s;
		bool flag = false;
		for (char c : str) {
			if (c == '(' || c == '[') s.push(c);
			else if (c == ')' || c == ']') {
				if (!s.empty() && c == ')' && s.top() == '(') s.pop();
				else if (!s.empty() && c == ']' && s.top() == '[') s.pop();
				else {
					cout << "no\n"; 
					flag = true; break;
				}
			}
		}
		if (!flag) {
			if (s.empty()) cout << "yes\n";
			else cout << "no\n";
		}
	}
	return 0;
}