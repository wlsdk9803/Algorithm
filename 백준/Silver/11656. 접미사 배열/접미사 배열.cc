#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	vector<string> v;
	for (int i = 0; i < str.length(); i++) v.push_back(str.substr(i));
	sort(v.begin(), v.end());
	for (string s : v) cout << s << "\n";
	return 0;
}