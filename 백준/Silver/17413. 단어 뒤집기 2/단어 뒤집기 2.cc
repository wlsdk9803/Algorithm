#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str; getline(cin, str);
    string temp = "";
    bool istag = false;
    for (int i = 0; i < str.length(); i++) {
        if (istag || str[i] == '<' || str[i] == '>' || str[i] == ' ') {
            if (str[i] == '<') istag = true;
            else if (str[i] == '>') istag = false;
            if (str[i] == '<' || str[i] == ' ') {
                reverse(temp.begin(), temp.end());
                cout << temp;
                temp = "";
            }
            cout << str[i]; continue;
        }
        temp += str[i];
    }
    if (temp != "") {
        reverse(temp.begin(), temp.end());
        cout << temp;
    }
    return 0;
}