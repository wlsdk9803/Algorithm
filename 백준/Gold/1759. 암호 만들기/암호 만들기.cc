#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int L, C; cin >> L >> C;
	vector<char> alpha(C);
	vector<int> temp;
	vector<char> aeiou{ 'a', 'e', 'i', 'o', 'u' };
	vector<string> result;
	for (int i = 0; i < C; i++) cin >> alpha[i];
	for (int i = 0; i < C - L; i++) temp.push_back(0);
	for (int i = 0; i < L; i++) temp.push_back(1);
	sort(alpha.begin(), alpha.end());
	do {
		string str = "";
		bool flag = false;
		int count_not = 0;
		for (int i = 0; i < C; i++) {
			if (temp[i] == 1) {
				str += alpha[i];
				if (find(aeiou.begin(), aeiou.end(), alpha[i]) == aeiou.end()) count_not++;
				else flag = true;
			}
		}
		if (flag && count_not >= 2) result.push_back(str);
	} while (next_permutation(temp.begin(), temp.end()));
	for (int i = result.size() - 1; i >= 0; i--) cout << result[i] << "\n";
	return 0;
}