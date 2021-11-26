#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>
#include <utility>
using namespace std;

typedef pair<int,int> p;
int maze[1000][1000] = {0};
bool visit[1000][1000] = {false};
int dst[1000][1000] = {0};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N,M;

void bfs(int x, int y) {
	visit[x][y] = true;
	queue<p> q;
	q.push(make_pair(x,y));
	
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		
		q.pop();
	
		for (int i=0; i<4; i++) {
			
			int nx = cur_x+dx[i];
			int ny = cur_y+dy[i];
			
			if (maze[nx][ny] == 1 && visit[nx][ny] == false) {
				dst[nx][ny] = dst[cur_x][cur_y] + 1;
				visit[nx][ny] = true;
				q.push(make_pair(nx,ny));
			}
		}
	}
}

int main(void) {
	string tmp;
	cin >> N >> M;
	
	for (int i=1; i<=N; i++) {
		cin >> tmp;
		for (int j=0; j<M; j++) maze[i][j+1] = tmp[j]-'0';
	}
	
	bfs(1,1);
	cout << dst[N][M]+1;
	return 0;
} 
