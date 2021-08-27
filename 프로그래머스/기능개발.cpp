#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = speeds.size();
    int n = 0;
    while(1) {
        int count = 0;
        for(int i=n; i<size; i++) progresses[i] += speeds[i];
        
        for(int i=n; i<size; i++) {
            if(progresses[i] >= 100) {
                count ++;
                n ++;
            }
            else break;
        }
        if(count) answer.push_back(count);
        if(n == size) break;
    }

    
    return answer;
}
