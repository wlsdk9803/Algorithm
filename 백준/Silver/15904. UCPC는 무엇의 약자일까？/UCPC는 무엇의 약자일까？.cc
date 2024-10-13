#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; getline(cin, str);
	string std = "UCPC"; int idx = 0;
	for (char c : str) {
		if (idx == 4) break;
		if (c == std[idx]) idx++;
	}
	if (idx == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";
	return 0;
}