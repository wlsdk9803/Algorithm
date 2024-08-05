#include <string>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(int num : array){
        string str = to_string(num);
        for(int i=0; i<str.length(); i++){
            if(str[i] == '7') answer++;
        }
    }
    return answer;
}