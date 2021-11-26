#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

int maze[27][27] = {false};
bool visit[27][27] = {false};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int sum[1000] = {0};

void dfs(int x, int y, int cur) {
	visit[x][y] = true;
	sum[cur]++;
	for (int i=0; i<4; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if (maze[nx][ny] == 0 || visit[nx][ny] == true) continue;
		
		dfs(nx, ny, cur);
	}
}

int main(void) {
	int N;
	string tmp;
	cin >> N;
	int cur = 1;
	for (int i=1; i<=N; i++) {
		cin >> tmp;
		for (int j=0; j<N; j++) maze[i][j+1] = tmp[j]-'0';
	}
	
	vector<int> answer;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			if (maze[i][j]==1 && visit[i][j]==false) {
				dfs(i,j,cur);
				cur++;	
			}
		}
	}
	for (int i=1; i<cur; i++) {
		answer.push_back(sum[i]);
	}
	sort(answer.begin(), answer.end());
	
	cout << cur-1 << '\n';
	for (int i=0; i<answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	
	return 0;
} 
