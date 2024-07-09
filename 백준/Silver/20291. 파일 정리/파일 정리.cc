#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    unordered_map<string, int> um;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string file; cin >> file;
        int pos = file.find_last_of('.');
        string extension = file.substr(pos + 1);
        if (um.find(extension) == um.end()) {
            um.insert({ extension, 1 });
            v.push_back(extension);
        }
        else um[extension]++;
    }
    sort(v.begin(), v.end());
    for (string s : v) cout << s << " " << um[s] << "\n";
    return 0;
}