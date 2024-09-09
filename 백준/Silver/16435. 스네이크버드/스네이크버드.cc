#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, L; cin >> N >> L;
	vector<int> h(N);
	for (int i = 0; i < N; i++) cin >> h[i];
	sort(h.begin(), h.end());
	for(int i=0; i<N; i++){
		if (h[i] <= L) L++;
	}
	cout << L;
	return 0;
}