#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int n = ingredient.size();
    stack<int> s;
    for(int i=0; i<n; i++){
        int num = ingredient[i];
        if(num == 2 || num == 3 || s.size() < 3) {
            s.push(num); continue;
        }
        for(int j=0; j<3; j++){
            int cur = s.top();
            if(j == 0){
                if(cur == 3) s.pop();
                else {
                    s.push(1); break;
                }
            }
            else if(j == 1){
                if(cur == 2) s.pop();
                else{
                    s.push(3); s.push(1); break;
                }
            }
            else {
                if(cur == 1) {
                    s.pop(); answer++;
                }
                else{
                    s.push(2); s.push(3); s.push(1); break;
                }
            }
        }
    }
    return answer;
}