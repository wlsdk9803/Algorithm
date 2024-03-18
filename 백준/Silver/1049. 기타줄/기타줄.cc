#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int package = 1000, one = 1000;
    for (int i = 0; i < m; i++) {
        int p, o; cin >> p >> o;
        package = min(p, package);
        one = min(o, one);
    }
    int money = min((n / 6) * package + min((n % 6) * one, package), n * one);
    cout << money;
    return 0;
}