#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		unordered_map<int, int> um;
		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			if (um.find(num) == um.end()) um.insert({ num, 1 });
		}
		int M; cin >> M;
		for (int i = 0; i < M; i++) {
			int num; cin >> num;
			if (um.find(num) == um.end()) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
	}
	return 0;
}