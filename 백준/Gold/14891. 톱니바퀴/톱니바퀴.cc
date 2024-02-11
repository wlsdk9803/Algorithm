#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string rotate(int clockwise, string str) {
	if (clockwise == 1) {
		char end = str[7];
		str.erase(7, 1);
		return end + str;
	}
	else {
		char start = str[0];
		str.erase(0, 1);
		return str + start;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string chain[5], pre_chain[5];
	for (int i = 1; i <= 4; i++) cin >> chain[i];

	int K; cin >> K;
	for (int index = 0; index < K; index++) {
		int num, clockwise;
		cin >> num >> clockwise;

		int pre_clockwise = clockwise;
		pre_chain[num] = chain[num];
		for (int i = num - 1; i >= 1; i--) {
			pre_chain[i] = chain[i];
			if (chain[i][2] != pre_chain[i + 1][6]) {
				pre_clockwise *= -1;
				chain[i] = rotate(pre_clockwise, chain[i]);
			}
			else break;
		}
		pre_clockwise = clockwise;
		for (int i = num + 1; i <= 4; i++) {
			pre_chain[i] = chain[i];
			if (chain[i][6] != pre_chain[i - 1][2]) {
				pre_clockwise *= -1;
				chain[i] = rotate(pre_clockwise, chain[i]);
			}
			else break;
		}
		chain[num] = rotate(clockwise, chain[num]);
	}
	cout << (chain[1][0] - '0') + 2 * (chain[2][0] - '0') + 4 * (chain[3][0] - '0') + 8 * (chain[4][0] - '0');
	return 0;
}