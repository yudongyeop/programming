#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    
    for(int i=1; i<triangle.size(); i++) {
        for(int j=0; j< triangle[i].size(); j++) {
            if(j == 0) triangle[i][j] += triangle[i-1][0];
            
            else if(j == triangle[i].size()-1) triangle[i][j] += *(triangle[i-1].end()-1);
            
            else triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
        }
    }
    
    answer = *max_element(triangle[size-1].begin(), triangle[size-1].end());
    
    return answer;
}
