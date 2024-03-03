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
	string res = "";
	for (int i = 0; i < count0 / 2; i++) res += '0';
	for (int i = 0; i < count1 / 2; i++) res += '1';
	cout << res;
	return 0;
}