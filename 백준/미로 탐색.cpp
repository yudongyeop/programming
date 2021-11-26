#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> maze;
bool visit[100][100] = {0}; 

void dfs(int x, int y, int seq, int N, int M, vector<int>& answer) {
	
	
	if (x == N-1 && y == M-1) {
		//cout << "x : " << x << " y : " << y << " seq : " << seq << endl;
		answer.push_back(seq);
	}
	
	else {	
		
		if (visit[x][y] == false) {
			//cout << "x : " << x << " y : " << y << " seq : " << seq << endl;
			visit[x][y] = true;
			if (y < M-1) 
				if(maze[x][y+1] == '1') dfs(x,y+1, seq+1, N, M, answer);
			if (x < N-1)
				if(maze[x+1][y] == '1') dfs(x+1,y, seq+1, N, M, answer);
			if (y > 0) 
				if (maze[x][y-1] == '1') dfs(x,y-1, seq+1, N, M, answer);	
			if (x > 0) 
				if(maze[x-1][y] == '1') dfs(x-1,y, seq+1, N, M, answer);
			
		} 
	}
}

int main(void) {
	int N, M;
	cin >> N >> M;
	vector<int> answer;
	string tmp;
	
	for (int i=0; i<N; i++) {
		cin >> tmp;
		maze.push_back(tmp);
	}
	

	dfs(0, 0, 0, N, M, answer);
	sort(answer.begin(), answer.end());
	cout << answer[0]+1 << endl;
	
}

