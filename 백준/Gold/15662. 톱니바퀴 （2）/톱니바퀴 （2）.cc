#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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
	int T; cin >> T;
	vector<string> chain(T + 1);
	vector<string> pre_chain(T + 1);
	for (int i = 1; i <= T; i++) cin >> chain[i];

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
		for (int i = num + 1; i <= T; i++) {
			pre_chain[i] = chain[i];
			if (chain[i][6] != pre_chain[i - 1][2]) {
				pre_clockwise *= -1;
				chain[i] = rotate(pre_clockwise, chain[i]);
			}
			else break;
		}
		chain[num] = rotate(clockwise, chain[num]);
	}
	int res = 0;
	for (int i = 1; i <= T; i++) {
		if (chain[i][0] == '1') res++;
	}
	cout << res;
	return 0;
}