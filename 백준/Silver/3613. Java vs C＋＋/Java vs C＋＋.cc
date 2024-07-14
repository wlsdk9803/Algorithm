#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str; cin >> str;
    string res = "";
    bool iscpp = false, isjava = false;
    bool isnextupper = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '_') {
            bool isok = false;
            if (str[i] >= 'a' && str[i] <= 'z') isok = true;
            else if (str[i] >= 'A' && str[i] <= 'Z') isok = true;
            if (!isok) {
                res = "Error!";
                break;
            }
        }
        if (i == 0) {
            if (str[i] == '_' || (str[i] >= 'A' && str[i] <= 'Z')) {
                res = "Error!";
                break;
            }
        }
        if (i == str.length() - 1 && str[i] == '_') {
            res = "Error!";
            break;
        }
        if (str[i] == '_') {
            if (isnextupper) {
                res = "Error!";
                break;
            }
            iscpp = true;
            isnextupper = true;
            continue;
        }
        if (isnextupper) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                res = "Error!";
                break;
            }
            res += toupper(str[i]);
            isnextupper = false;
            continue;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            isjava = true;
            res += "_";
            res += tolower(str[i]);
            continue;
        }
        res += str[i];
    }
    if (iscpp && isjava) res = "Error!";
    cout << res;
    return 0;
}