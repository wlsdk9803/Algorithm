#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int max_int = 8000000;
	vector<bool> isprime(max_int, true);
	isprime[0] = false; isprime[1] = false;
	for (int i = 2; i * i < max_int; i++) {
		for (int j = i * i; j < max_int; j += i) {
			if (isprime[j]) isprime[j] = false;
		}
	}
	vector<int> primes;
	for (int i = 2; i < max_int; i++) {
		if (isprime[i]) primes.push_back(i);
	}
	int K; cin >> K;
	cout << primes[K - 1];
	return 0;
}