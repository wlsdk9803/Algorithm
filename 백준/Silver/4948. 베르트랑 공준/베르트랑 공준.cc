#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int max_num = 123456 * 2;
	vector<bool> isprime(max_num + 1, true);
	isprime[0] = false; isprime[1] = false;
	for (int i = 2; i * i <= max_num; i++) {
		if (isprime[i]) {
			for (int j = i * i; j <= max_num; j += i) isprime[j] = false;
		}
	}
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		int count = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isprime[i]) count++;
		}
		cout << count << "\n";
	}
	return 0;
}