#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<bool> isprime(1000001, true);
	isprime[0] = false; isprime[1] = false;
	for (int i = 2; i * i <= 1000000; i++) {
		if (isprime[i]) {
			for (int j = i * i; j <= 1000000; j += i) isprime[j] = false;
		}
	}
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int num; cin >> num;
		int a = 2, b = num - 2;
		int count = 0;
		while (a <= b) {
			if (isprime[a] && isprime[b]) count++;
			if (a == 2) {
				a++; b--;
			}
			else {
				a += 2; b -= 2;
			}
		}
		cout << count << "\n";
	}
	return 0;
}
