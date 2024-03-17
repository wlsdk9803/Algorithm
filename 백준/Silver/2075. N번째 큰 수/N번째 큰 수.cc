#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    priority_queue<long long> pq;
    for (int i = 0; i < n * n; i++) {
        long long num; cin >> num;
        pq.push(-num);
        if (pq.size() > n) pq.pop();
    }
    cout << -pq.top();
    return 0;
}
