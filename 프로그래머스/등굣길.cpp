#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> board(n, vector<int>(m, 1));
    
    for(int i=0; i<puddles.size(); i++) {
        int x = puddles[i][0]-1;
        int y = puddles[i][1]-1;
        board[y][x] = 0;
        
        if(x==0) {
            for(int i=y; i<n; i++) {
                board[i][0] = 0;
            }
        }
        if(y==0) {
            for(int i=x; i<m; i++) {
                board[0][i] = 0;
            }
        }
    }
    for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(board[i][j] != 0) {
                    board[i][j] = (board[i-1][j] + board[i][j-1]) % 1000000007;
                }
            }
    }
    
    int answer = board[n-1][m-1];             
    return answer;
}
