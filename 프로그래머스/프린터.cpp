#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<vector<int>> r;
    int size = priorities.size();
    for(int i=0; i<size; i++) {
        vector<int> e;
        e.push_back(priorities[i]);
        e.push_back(i);
        r.push_back(e);
    }
    while(true) {
        bool rev = false;
        for(int i=1; i<size; i++) {
            if(r[0][0] < r[i][0]) {
                r.push_back(r[0]);
                r.erase(r.begin());
                rev = true;
                break;
            }
        }
        if(!rev) {
            answer++;
            r[0][0] = -1;
            if(r[0][1] == location) break;
        }
    }
    return answer;
}
