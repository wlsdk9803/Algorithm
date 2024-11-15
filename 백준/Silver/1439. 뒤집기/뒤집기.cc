#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	vector<int> count(2);
	char prev = str[0];
	for (int i = 1; i < str.length(); i++) {
		if (str[i] != prev) {
			count[prev - '0']++;
			prev = str[i];
		}
	}
	count[prev - '0']++;
	cout << min(count[0], count[1]);
	return 0;
}