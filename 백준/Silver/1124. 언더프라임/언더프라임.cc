#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b; cin >> a >> b;
	vector<bool> isprime(100001, true);
	isprime[0] = false; isprime[1] = false;
	for (int i = 2; i * i <= 100000; i++) {
		for (int j = i * i; j <= 100000; j += i) {
			if (isprime[j]) isprime[j] = false;
		}
	}
	vector<int> primes;
	for (int i = 2; i <= 100000; i++) {
		if (isprime[i]) primes.push_back(i);
	}
	int res = 0;
	for (int num = a; num <= b; num++) {
		if (isprime[num]) continue;
		int count = 0;
		int temp = num;
		for (int prime : primes) {
			while (temp % prime == 0) {
				count++;
				temp /= prime;
			}
			if (temp == 1) break;
		}
		if (isprime[count]) res++;
	}
	cout << res;
	return 0;
}