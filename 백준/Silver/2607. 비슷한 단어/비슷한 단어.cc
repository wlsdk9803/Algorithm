#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

unordered_map<char, int> calculate_um(string str) {
	unordered_map<char, int> um;
	vector<char> v;
	for (int i = 0; i < str.length(); i++) {
		if (find(v.begin(), v.end(), str[i]) == v.end()) {
			v.push_back(str[i]);
			um[str[i]] = 1;
		}
		else um[str[i]]++;
	}
	return um;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string fir; cin >> fir;
	unordered_map<char, int> fir_um = calculate_um(fir);

	int res = 0;
	for (int idx = 1; idx < n; idx++) {
		string str; cin >> str;
		unordered_map<char, int> um = calculate_um(str);
		vector<pair<char, int>> temp;
		bool flag = true;
		for (char alpha = 'A'; alpha <= 'Z'; alpha++) {
			if (um[alpha] == fir_um[alpha]) continue;
			else if (abs(um[alpha] - fir_um[alpha]) > 1) {
				flag = false; break;
			}
			else temp.push_back({ alpha, um[alpha] - fir_um[alpha] });
		}
		if (flag && (temp.size() == 0 || temp.size() == 1)) res++;
		else if (flag && temp.size() == 2 && abs(temp[0].second - temp[1].second) == 2) res++;
	}
	cout << res;
	return 0;
}