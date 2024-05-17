#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	vector<int> v;
	for (int i = 0; i < str.length(); i++) v.push_back(str[i] - '0');
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < v.size(); i++) cout << v[i];
	return 0;
}