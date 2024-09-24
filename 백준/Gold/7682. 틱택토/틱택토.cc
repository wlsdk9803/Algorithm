#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkX(vector<vector<char>> v) {
	for (int i = 0; i < 3; i++) {
		if (v[i][0] == 'X' && v[i][0] == v[i][1] && v[i][1] == v[i][2]) return true;
		if (v[0][i] == 'X' && v[0][i] == v[1][i] && v[1][i] == v[2][i]) return true;
	}
	if (v[0][0] == 'X' && v[0][0] == v[1][1] && v[1][1] == v[2][2]) return true;
	if (v[0][2] == 'X' && v[0][2] == v[1][1] && v[1][1] == v[2][0]) return true;
	return false;
}
bool checkO(vector<vector<char>> v) {
	for (int i = 0; i < 3; i++) {
		if (v[i][0] == 'O' && v[i][0] == v[i][1] && v[i][1] == v[i][2]) return true;
		if (v[0][i] == 'O' && v[0][i] == v[1][i] && v[1][i] == v[2][i]) return true;
	}
	if (v[0][0] == 'O' && v[0][0] == v[1][1] && v[1][1] == v[2][2]) return true;
	if (v[0][2] == 'O' && v[0][2] == v[1][1] && v[1][1] == v[2][0]) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		string str; cin >> str;
		if (str == "end") return 0;
		int numX = 0, numO = 0;
		vector<vector<char>> v(3, vector<char>(3));
		for (int i = 0; i < 9; i++) {
			v[i / 3][i % 3] = str[i];
			if (str[i] == 'X') numX++;
			else if (str[i] == 'O') numO++;
		}
		bool isX = checkX(v);
		bool isO = checkO(v);
		if (numX == numO && isO && !isX) cout << "valid\n";
		else if (numX == numO + 1 && isX && !isO) cout << "valid\n";
		else if (numX == 5 && numO == 4 && !isO && !isX) cout << "valid\n";
		else cout << "invalid\n";
	}
	return 0;
}