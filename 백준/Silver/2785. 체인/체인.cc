#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    vector<int> dist(n, 1001);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    deque<int> dq;
    for (int i = 0; i < n; i++) dq.push_back(v[i]);
    if (dq.size() == 2) {
        cout << 1;
        return 0;
    }

    int res = 0;
    while (dq.size() >= 3) {
        int f = dq.front(); dq.pop_front();
        int r_fir = dq.back(); dq.pop_back();
        int r_sec = dq.back(); dq.pop_back();
        f--; res++;
        dq.push_back(r_fir + r_sec);
        if (f > 0) dq.push_front(f);
    }
    if (dq.size() == 2) res++;
    cout << res;
    return 0;
}