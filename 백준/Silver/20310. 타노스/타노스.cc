#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string S; cin >> S;
	int count0 = 0, count1 = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '0') count0++;
		else count1++;
	}
	int count = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '1') {
			S.erase(i, 1);
			i--;
			count++;
		}
		if (count == count1 / 2) break;
	}
	count = 0;
	for (int i = S.length() - 1; i >= 0; i--) {
		if (S[i] == '0') {
			S.erase(i, 1);
			i++;
			count++;
		}
		if (count == count0 / 2) break;
	}
	cout << S;
	return 0;
}