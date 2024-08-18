#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		s.push(str[i]);
		if (s.size() < 4) continue;
		if (s.top() == 'P') {
			s.pop();
			if (s.top() == 'A') {
				s.pop();
				if (s.top() == 'P') {
					s.pop();
					if (s.top() != 'P') {
						s.push('P'); s.push('A'); s.push('P');
					}
				}
				else {
					s.push('A'); s.push('P');
				}
			}
			else s.push('P');
		}
	}
	if (s.size() == 1 && s.top() == 'P') cout << "PPAP";
	else cout << "NP";
    return 0;
}