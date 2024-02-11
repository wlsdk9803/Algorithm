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
		switch (num) {
		case 1:
			if (chain[1][2] != chain[2][6]) {
				pre_chain[2] = chain[2];
				chain[2] = rotate(-1 * clockwise, chain[2]);
				if (pre_chain[2][2] != chain[3][6]) {
					pre_chain[3] = chain[3];
					chain[3] = rotate(clockwise, chain[3]);
					if (pre_chain[3][2] != chain[4][6]) {
						chain[4] = rotate(-1 * clockwise, chain[4]);
					}
				}
			}
			chain[1] = rotate(clockwise, chain[1]);
			break;
		case 2:
			if (chain[2][6] != chain[1][2]) chain[1] = rotate(-1 * clockwise, chain[1]);
			if (chain[2][2] != chain[3][6]) {
				pre_chain[3] = chain[3];
				chain[3] = rotate(-1 * clockwise, chain[3]);
				if (pre_chain[3][2] != chain[4][6]) {
					chain[4] = rotate(clockwise, chain[4]);
				}
			}
			chain[2] = rotate(clockwise, chain[2]);
			break;
		case 3:
			if (chain[3][2] != chain[4][6]) chain[4] = rotate(-1 * clockwise, chain[4]);
			if (chain[3][6] != chain[2][2]) {
				pre_chain[2] = chain[2];
				chain[2] = rotate(-1 * clockwise, chain[2]);
				if (pre_chain[2][6] != chain[1][2]) {
					chain[1] = rotate(clockwise, chain[1]);
				}
			}
			chain[3] = rotate(clockwise, chain[3]);
			break;
		case 4:
			if (chain[4][6] != chain[3][2]) {
				pre_chain[3] = chain[3];
				chain[3] = rotate(-1 * clockwise, chain[3]);
				if (pre_chain[3][6] != chain[2][2]) {
					pre_chain[2] = chain[2];
					chain[2] = rotate(clockwise, chain[2]);
					if (pre_chain[2][6] != chain[1][2]) {
						chain[1] = rotate(-1 * clockwise, chain[1]);
					}
				}
			}
			chain[4] = rotate(clockwise, chain[4]);
			break;
		}
	}
	cout << (chain[1][0] - '0') + 2 * (chain[2][0] - '0') + 4 * (chain[3][0] - '0') + 8 * (chain[4][0] - '0');
	return 0;
}