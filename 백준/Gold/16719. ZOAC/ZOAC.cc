#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<bool> isused;

void solve(int start, int end) {
	int min_idx = start;
	for (int i = start; i <= end; i++) {
		if (str[min_idx] > str[i]) min_idx = i;
	}
	isused[min_idx] = true;
	for (int i = 0; i < str.length(); i++) {
		if (isused[i]) cout << str[i];
	}
	cout << "\n";
	if (min_idx + 1 <= end) solve(min_idx + 1, end);
	if (min_idx - 1 >= start) solve(start, min_idx - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str;
	isused.resize(str.length());
	solve(0, str.length() - 1);
	return 0;
}