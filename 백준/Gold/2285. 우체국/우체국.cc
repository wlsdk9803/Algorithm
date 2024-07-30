#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<pair<long long, long long>> v(N);
	long long total = 0;
	for (int i = 0; i < N; i++) {
		int x, a; cin >> x >> a;
		v[i] = make_pair(x, a);
		total += a;
	}
	sort(v.begin(), v.end());
	long long accumulation = 0;
	for (int i = 0; i < N; i++) {
		accumulation += v[i].second;
		if (accumulation >= (total + 1) / 2) {
			cout << v[i].first;
			break;
		}
	}
    return 0;
}