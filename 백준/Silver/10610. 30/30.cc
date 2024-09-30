#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	sort(str.begin(), str.end(), greater<>());
	int sum = 0;
	for (int i = 0; i < str.length(); i++) sum = (sum + (str[i] - '0')) % 3;
	if (str.back() == '0' && sum == 0) cout << str;
	else cout << -1;
	return 0;
}