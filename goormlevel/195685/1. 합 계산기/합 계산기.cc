#include <iostream>

using namespace std;

int calculate(int a, int b, char oper){
	if(oper == '+') return a + b;
	if(oper == '-') return a - b;
	if(oper == '*') return a * b;
	if(oper == '/') return a / b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	int res = 0;
	for(int test=0; test<T; test++){
		int a, b; char oper;
		cin >> a >> oper >> b;
		res += calculate(a, b, oper);
	}
	cout << res;
	return 0;
}