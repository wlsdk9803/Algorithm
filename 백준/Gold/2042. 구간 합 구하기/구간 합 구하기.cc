#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;
vector<long long> tree;

long long make_segmentTree(int start, int end, int index) {
	if (start == end) return tree[index] = arr[start];
	int mid = (start + end) / 2;
	return tree[index] = make_segmentTree(start, mid, 2 * index) + make_segmentTree(mid + 1, end, 2 * index + 1);
}
void update_segmentTree(int start, int end, int index, int what, long long diff) {
	if (what < start || what > end) return;
	tree[index] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update_segmentTree(start, mid, index * 2, what, diff);
	update_segmentTree(mid + 1, end, index * 2 + 1, what, diff);
}
long long sum_segmentTree(int start, int end, int index, int left, int right) {
	if (left > end || right < start) return 0;
	else if (left <= start && right >= end) return tree[index];
	int mid = (start + end) / 2;
	return sum_segmentTree(start, mid, 2 * index, left, right) + sum_segmentTree(mid + 1, end, 2 * index + 1, left, right);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, K; cin >> N >> M >> K;
	arr.resize(N);
	tree.resize(4 * N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	make_segmentTree(0, N - 1, 1);
	for (int i = 0; i < M + K; i++) {
		long long a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			update_segmentTree(0, N - 1, 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else if (a == 2) cout << sum_segmentTree(0, N - 1, 1, b - 1, c - 1) << "\n";
	}
	return 0;
}
