#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unordered_set<string> dancers;
	dancers.insert("ChongChong");
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string A, B; cin >> A >> B;
		if (dancers.find(A) != dancers.end() || dancers.find(B) != dancers.end()) {
			dancers.insert(A);
			dancers.insert(B);
		}
	}
	cout << dancers.size();
	return 0;
}