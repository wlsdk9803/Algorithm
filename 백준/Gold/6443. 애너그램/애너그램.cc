#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for (int test = 0; test < N; test++) {
		string str; cin >> str;
		sort(str.begin(), str.end());
		do {
			cout << str << "\n";
		} while (next_permutation(str.begin(), str.end()));
	}
	return 0;
}