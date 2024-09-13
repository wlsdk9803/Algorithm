#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int N, M; cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
		}
		cout << N - 1 << "\n";
	}
	return 0;
}