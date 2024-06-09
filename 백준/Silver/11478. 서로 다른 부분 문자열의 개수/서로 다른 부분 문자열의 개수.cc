#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	set<string> substrs;
	for (int i = 0; i < str.length(); i++) {
		for (int j = 1; j <= str.length() - i; j++) {
			substrs.insert(str.substr(i, j));
		}
	}
	cout << substrs.size();
	return 0;
}