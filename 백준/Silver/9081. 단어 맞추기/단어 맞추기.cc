#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		string str; cin >> str;
		vector<char> v;
		for (char c : str) v.push_back(c);

		bool isequal = false;
		do {
			string temp = "";
			for (int i = 0; i < v.size(); i++) temp += v[i];
			if (isequal) {
				cout << temp << "\n";
				isequal = false;
				break;
			}
			if (temp == str) isequal = true;
		} while (next_permutation(v.begin(), v.end()));
		if (isequal) cout << str << "\n";
	}
    return 0;
}