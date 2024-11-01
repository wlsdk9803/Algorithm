#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> isPrime(10001, true);
	isPrime[0] = false; isPrime[1] = false;
	for (int i = 2; i * i <= 10000; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 10000; j += i) isPrime[j] = false;
		}
	}
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int n; cin >> n;
		int a = n / 2, b = n / 2;
		while (!isPrime[a] || !isPrime[b]) {
			a--; b++;
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}