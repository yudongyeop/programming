//BFS solution
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

vector<int> answer;
int visited[300][300];
int T,L;

int sx, sy, dx, dy;

int mx[] = {-2,-1,1,2,2,1,-1,-2};
int my[] = {1,2,2,1,-1,-2,-2,-1};

typedef pair<int, int> p;

int bfs() {
	queue<p> q;
	q.push(make_pair(sx,sy));
	visited[sx][sy] = 1;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (x == dx && y == dy) return visited[dx][dy];
		
		for (int i=0; i<8; i++) {
			int nx = x+mx[i];
			int ny = y+my[i];
			
			if (nx >= L || nx < 0 || ny >= L || ny < 0) continue;
			
			if (visited[nx][ny] == 0) {
				visited[nx][ny] = visited[x][y]+1;
				q.push(make_pair(nx,ny));
			}
		}
		
	}
	return -1;
}


int main(void) {
	cin >> T;
	int tmp;
	
	for (int i=0; i<T; i++) {
		cin >> L;
		cin >> tmp;
		sx = tmp;
		cin >> tmp;
		sy = tmp;
		cin >> tmp;
		dx = tmp;
		cin >> tmp;
		dy = tmp;
		
		
		answer.push_back(bfs());
		memset(visited,0,sizeof(visited));
	}
	
	for (int i=0; i<answer.size(); i++) cout << answer[i]-1 << '\n';
	
	return 0;	
}
