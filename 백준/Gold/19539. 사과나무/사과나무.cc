#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int total_sum = 0, div2_sum = 0;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		total_sum += num;
		div2_sum += num / 2;
	}
	if (total_sum % 3 == 0 && div2_sum >= (total_sum / 3)) cout << "YES";
	else cout << "NO";
	return 0;
}