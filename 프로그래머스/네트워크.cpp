#include <string>
#include <vector>

using namespace std;

void search(vector<vector<int>> computers, int num, int i, int size, bool* visited) {
    if (visited[i] == true) return;
    visited[i] = true;
    computers[i][num] = -1;
    
    for(int j=0; j<size; j++) {
        if(computers[i][j] == 1) search(computers, i, j, size, visited); 
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int size = computers[0].size();
    bool visited[size];
    for (int i=0; i<size; i++) {
        visited[i] = false;
    }
    for (int i=0; i<size; i++) {
        if(visited[i] == false) {
            search(computers, i, i, size, visited);
            answer++;
        }
    }
    return answer;
}


