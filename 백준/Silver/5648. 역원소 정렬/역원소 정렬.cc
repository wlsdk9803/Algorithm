#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long num; cin >> num;
		string str = to_string(num);
		reverse(str.begin(), str.end());
		v.push_back(stoll(str));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) cout << v[i] << "\n";
	return 0;
}