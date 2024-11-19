#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int max_prime = 1299709;
	vector<bool> isprime(max_prime + 1, true);
	isprime[0] = false; isprime[1] = false;
	for (int i = 2; i * i <= max_prime; i++) {
		for (int j = i * i; j <= max_prime; j += i) {
			if (isprime[j]) isprime[j] = false;
		}
	}
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int k; cin >> k;
		if (isprime[k]) {
			cout << 0 << "\n";
			continue;
		}
		int right = -1, left = -1;
		for (int i = k - 1; i >= 2; i--) {
			if (isprime[i]) {
				left = i; break;
			}
		}
		for (int i = k + 1; k <= max_prime; i++) {
			if (isprime[i]) {
				right = i; break;
			}
		}
		cout << right - left << "\n";
	}
	return 0;
}