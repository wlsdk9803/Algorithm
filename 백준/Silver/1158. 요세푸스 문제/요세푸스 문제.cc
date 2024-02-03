#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	vector<int> v;
	for (int i = 0; i < N; i++) v.push_back(i);

	cout << "<";
	int pointer = K - 1;
	while (v.size() > 0) {
		if (v.size() > 1) cout << v[pointer] + 1 << ", ";
		else cout << v[pointer] + 1;
		v.erase(v.begin() + pointer);
		if(v.size() != 0) pointer = (pointer + K - 1) % v.size();
	}
	cout << ">";
	return 0;
}