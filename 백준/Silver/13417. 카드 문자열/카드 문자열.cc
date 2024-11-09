#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int N; cin >> N;
		string str = "";
		for (int i = 0; i < N; i++) {
			char c; cin >> c;
			if (i == 0) str = c;
			else if (c <= str[0]) str = c + str;
			else str += c;
		}
		cout << str << "\n";
	}
	return 0;
}