#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    unordered_map<string, bool> um;
    bool flag = false;
    for(int i=0; i<phone_book.size(); i++){
        string cur = phone_book[i];
        for(int j=1; j<=cur.length(); j++){
            if(um.find(cur.substr(0, j)) != um.end()){
                answer = false;
                flag = true;
                break;
            }
        }
        if(flag) break;
        um.insert({cur, true});
    }
    return answer;
}