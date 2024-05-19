#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comp(string s1, string s2) {
	if(s1.length() != s2.length()) return s1.length() < s2.length();
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] >= '0' && s1[i] <= '9') sum1 += s1[i] - '0';
		if (s2[i] >= '0' && s2[i] <= '9') sum2 += s2[i] - '0';
	}
	if (sum1 != sum2) return sum1 < sum2;
	return s1 < s2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++) cout << v[i] << "\n";
	return 0;
}