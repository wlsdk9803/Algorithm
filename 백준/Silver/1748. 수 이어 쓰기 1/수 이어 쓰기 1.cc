#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string n; cin >> n;
	int res = 0;
	int len = n.length();
	int high = stoi(n), low = pow(10, len - 1);
	while (low > 1) {
		res += (high - low + 1) * len;
		len--;
		high = low - 1;
		low = pow(10, len - 1);
	}
	res += high - low + 1;
	cout << res;
	return 0;
}