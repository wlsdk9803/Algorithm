#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> v;
	unordered_map<int, int> um;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
		um.insert({ num, 0 });
	}
	for (int i = 0; i < n; i++) {
		for (int j = v[i] * 2; j <= 1000000; j += v[i]) {
			if (um.find(j) != um.end()) {
				um[j]--;
				um[v[i]]++;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << um[v[i]] << " ";
    return 0;
}