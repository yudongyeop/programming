#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h = citations.size();
    while(h >= 0) {
        int count = 0;
        for(int i=0; i<citations.size(); i++) {
            if(citations[i] >= h) count++;
        }
        if(count >= h) break;
        h--;
    }
    answer = h;
    return answer;


}
