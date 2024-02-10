#include <iostream>
#include <cmath>

using namespace std;

long long sum_f(long long x) {
	if (x <= 0) return 0;
	long long index = floor(log2(x));
	long long pow2_index = pow(2, index);
	if (x == pow2_index) return index * x / 2 + 1;
	else {
		long long diff = x - pow2_index;
		return sum_f(pow2_index) + diff + sum_f(diff);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long a, b; cin >> a >> b;
	cout << sum_f(b) - sum_f(a - 1);
	return 0;
}