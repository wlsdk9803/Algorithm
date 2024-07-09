#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> max_heap;
    priority_queue<int> min_heap;
    priority_queue<int> temp;
    for(int i=0; i<operations.size(); i++){
        switch(operations[i][0]){
            case 'I':{
                int num = stoi(operations[i].substr(2));
                max_heap.push(num);
                min_heap.push(-num);
                break;
            }
            case 'D': {
                if(max_heap.empty()) break;
                if(operations[i][2] == '1') {
                    max_heap.pop();
                    temp = max_heap;
                    min_heap = priority_queue<int>();
                    while(!temp.empty()) {
                        int n = temp.top(); temp.pop();
                        min_heap.push(-n);
                    }
                }
                else {
                    min_heap.pop();
                    temp = min_heap;
                    max_heap = priority_queue<int>();
                    while(!temp.empty()) {
                        int n = temp.top(); temp.pop();
                        max_heap.push(-n);
                    }
                }
                break;
            }
        }
    }
    if(max_heap.empty()) answer = {0, 0};
    else{
        answer.push_back(max_heap.top());
        answer.push_back(-min_heap.top());
    }
    return answer;
}