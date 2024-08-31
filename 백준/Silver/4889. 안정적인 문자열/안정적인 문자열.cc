#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test = 1;
	while (true) {
		string str; cin >> str;
		if (str[0] == '-') break;
		int res = 0;
		stack<char> s;
		for (char c : str) {
			if (s.empty()) {
				s.push('{');
				if (c == '}') res++;
				continue;
			}
			if (c == '{') s.push(c);
			else s.pop();
		}
		res += s.size() / 2;
		cout << test << ". " << res << "\n";
		test++;
	}
	return 0;
}