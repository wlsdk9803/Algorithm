#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<char> alpha;
	unordered_map<char, int> um;
	for (int idx = 0; idx < n; idx++) {
		string str; cin >> str;
		for (int i = 0; i < str.length(); i++) {
			int pos = str.length() - 1 - i;
			if (find(alpha.begin(), alpha.end(), str[i]) == alpha.end()) {
				alpha.push_back(str[i]);
				um[str[i]] = pow(10, pos);
			}
			else um[str[i]] += pow(10, pos);
		}
	}
	priority_queue<int> pq;
	for (int i = 0; i < alpha.size(); i++) pq.push(um[alpha[i]]);
	int num = 9;
	long long sum = 0;
	while (!pq.empty()) {
		sum += num * pq.top();
		pq.pop();
		num--;
	}
	cout << sum;
	return 0;
}