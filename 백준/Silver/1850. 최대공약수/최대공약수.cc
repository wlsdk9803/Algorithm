#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	long long max = a > b ? a : b;
	long long min = a < b ? a : b;
	long long mod = max % min;
	if (mod == 0) return min;
	return gcd(min, mod);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long a, b; cin >> a >> b;
	long long res = gcd(a, b);
	for (long long i = 0; i < res; i++) cout << 1;
	return 0;
}