#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> split(char delimiter, string str) {
	istringstream iss(str);
	string buffer;
	vector<string> result;
	while (getline(iss, buffer, delimiter)) result.push_back(buffer);
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	cin.ignore();
	for (int test = 0; test < T; test++) {
		string sound; getline(cin, sound);
		vector<string> cryings = split(' ', sound);
		unordered_map<string, bool> um;
		while (true) {
			string input; getline(cin, input);
			if (input == "what does the fox say?") break;
			vector<string> inputs = split(' ', input);
			um.insert({ inputs[2], true });
		}
		for (string crying : cryings) {
			if (um.find(crying) == um.end()) cout << crying << " ";
		}
		cout << "\n";
	}
	return 0;
}