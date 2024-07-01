#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unordered_map<string, int> um;
	vector<string> v;
	int sum = 0;
	string str;
	while (getline(cin, str)) {
		if (um.find(str) == um.end()) {
			um.insert({ str, 1 });
			v.push_back(str);
		}
		else um[str]++;
		sum++;
	}
	sort(v.begin(), v.end());
	cout << fixed << setprecision(4);
	for (string str : v) {
		double percentage = (double)um[str] / sum * 100;
		cout << str << " " << percentage << "\n";
	}
	return 0;
}