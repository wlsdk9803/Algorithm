#include <iostream>
#include <unordered_map>

using namespace std;

long long N, P, Q;
unordered_map<long long, long long> A(N + 1);

long long recursion(long long N) {
    if (N == 0) return A[0] = 1;
    if (A[N] != 0) return A[N];
    return A[N] = recursion(N / P) + recursion(N / Q);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> P >> Q;
    cout << recursion(N);
    return 0;
}