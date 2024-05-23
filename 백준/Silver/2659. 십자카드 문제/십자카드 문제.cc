#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int get_clock_num(string snum) {
	vector<string> v(4);
	for (int i = 0; i < 4; i++) {
		v[i] = snum.substr(i) + snum.substr(0, i);
	}
	sort(v.begin(), v.end());
	return stoi(v[0]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str = "";
	for (int i = 0; i < 4; i++) {
		string x; cin >> x;
		str += x;
	}
	int cur_clock_num = get_clock_num(str);
	set<int> all_clock_numbers;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				for (int l = 1; l <= 9; l++) {
					string num = to_string(i) + to_string(j) + to_string(k) + to_string(l);
					int clock_num = get_clock_num(num);
					all_clock_numbers.insert(clock_num);
				}
			}
		}
	}
	cout << distance(all_clock_numbers.begin(), all_clock_numbers.find(cur_clock_num)) + 1;
	return 0;
}