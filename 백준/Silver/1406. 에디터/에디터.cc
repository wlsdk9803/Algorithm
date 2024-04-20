#include <iostream>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	list<char> li;
	for (int i = 0; i < str.length(); i++) li.push_back(str[i]);
	list<char>::iterator cur = li.end();
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		char cmd; cin >> cmd;
		switch (cmd) {
		case 'P':
			char c; cin >> c;
			li.insert(cur, c);
			break;
		case 'B':
			if (cur != li.begin()) cur = li.erase(--cur);
			break;
		case 'D':
			if (cur != li.end()) cur++;
			break;
		case 'L':
			if (cur != li.begin()) cur--;
			break;
		}
	}
	for (auto i : li) cout << i;
	return 0;
}
