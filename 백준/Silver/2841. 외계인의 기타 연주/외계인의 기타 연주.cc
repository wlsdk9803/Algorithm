#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p; cin >> n >> p;
    vector<priority_queue<int>> v(n + 1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int string_num, fret_num;
        cin >> string_num >> fret_num;
        if (!v[string_num].empty() && fret_num == v[string_num].top()) continue;
        while (!v[string_num].empty() && fret_num < v[string_num].top()) {
            v[string_num].pop();
            res++;
        }
        if (v[string_num].empty() || fret_num > v[string_num].top()) {
            v[string_num].push(fret_num);
            res++;
        }
    }
    cout << res;
    return 0;
}