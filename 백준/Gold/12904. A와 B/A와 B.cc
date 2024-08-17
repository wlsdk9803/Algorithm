#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string S, T; cin >> S >> T;
	while (T.length() > S.length()) {
		int n = T.length();
		if (T[n - 1] == 'B') reverse(T.begin(), T.end() - 1);
		T = T.substr(0, n - 1);
	}
	if (T == S) cout << 1;
	else cout << 0;
    return 0;
}