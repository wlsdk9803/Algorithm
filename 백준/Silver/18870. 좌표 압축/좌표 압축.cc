#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back(num);
        s.insert(num);
    }
    unordered_map<int, int> um;
    int cnt = 0;
    for (int num : s) {
        um.insert({ num, cnt });
        cnt++;
    }
    for (int num : v) cout << um[num] << " ";
    return 0;
}
