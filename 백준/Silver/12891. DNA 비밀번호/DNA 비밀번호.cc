#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> v(4); // A, C, G, T 순
unordered_map<char, int> um;

bool isOk() {
	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0:
			if (v[i] > um['A']) return false;
			break;
		case 1:
			if (v[i] > um['C']) return false;
			break;
		case 2:
			if (v[i] > um['G']) return false;
			break;
		case 3:
			if (v[i] > um['T']) return false;
			break;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int S, P; cin >> S >> P;
	string str; cin >> str;
	for (int i = 0; i < 4; i++) cin >> v[i];

	int fir_idx = 0, last_idx = P - 1;
	for (int i = fir_idx; i <= last_idx; i++) {
		if (um.find(str[i]) == um.end()) um.insert({ str[i], 1 });
		else um[str[i]]++;
	}
	long long count = 0;
	while (last_idx < S) {
		if (isOk()) count++;
		if (last_idx == S - 1) break;
		um[str[fir_idx++]]--;
		um[str[++last_idx]]++;
	}
	cout << count;
	return 0;
}