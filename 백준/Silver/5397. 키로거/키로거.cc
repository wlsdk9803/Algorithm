#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		string str; cin >> str;
		list<char> li;
		list<char>::iterator iter = li.begin();
		for (int i = 0; i < str.length(); i++) {
			switch (str[i]) {
			case '<':
				if (iter != li.begin()) iter--;
				break;
			case '>':
				if (iter != li.end()) iter++;
				break;
			case '-':
				if (iter != li.begin()) iter = li.erase(--iter);
				break;
			default:
				li.insert(iter, str[i]);
				break;
			}
		}
		for (auto res : li) cout << res;
		cout << "\n";
	}
	return 0;
}