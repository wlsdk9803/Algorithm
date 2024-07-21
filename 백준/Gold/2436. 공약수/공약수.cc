#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int get_gcd(int a, int b) {
    if (b % a == 0) return a;
    return get_gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int gcd, lcm; cin >> gcd >> lcm;
    int lcm_div_gcd = lcm / gcd;

    vector<int> v;
    for (int i = 1; i <= lcm_div_gcd / 2; i++) {
        if (lcm_div_gcd % i == 0) v.push_back(i);
    }
    v.push_back(lcm_div_gcd);

    int left_idx, right_idx;
    int left, right;
    if (v.size() % 2 == 0) {
        left_idx = v.size() / 2 - 1;
        right_idx = v.size() / 2;
    }
    else {
        left_idx = v.size() / 2;
        right_idx = v.size() / 2;
    }
    left = v[left_idx];
    right = v[right_idx];

    while (get_gcd(left, right) > 1) {
        left_idx--;
        right_idx++;
        left = v[left_idx];
        right = v[right_idx];
    }
    cout << left * gcd << " " << right * gcd;
    return 0;
}