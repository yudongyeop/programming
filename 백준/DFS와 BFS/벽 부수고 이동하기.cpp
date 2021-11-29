#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <string>
using namespace std;

int map[1000][1000];
int visit[1000][1000][2];


int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

typedef tuple<int,int,int> t;

int N,M;

int bfs(void) {
	queue<t> q;
	q.push(make_tuple(0,0,true));
	visit[0][0][1] = 1;
	
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int crash = get<2>(q.front());
		q.pop();
		
		if (x == N-1 && y == M-1) {
			return visit[x][y][crash];
		}
		
		//cout << "x: " << x << " y: " << y << " crash : " << crash << endl;
		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			
				if (map[nx][ny] == 1 && crash) {
					q.push(make_tuple(nx,ny,0));
					visit[nx][ny][crash-1] = visit[x][y][crash]+1;
				}
				else if (map[nx][ny] == 0 && visit[nx][ny][crash] == 0) {
					q.push(make_tuple(nx,ny,crash));
					visit[nx][ny][crash] = visit[x][y][crash]+1;
				}
			}
		}
	}
	
	return -1;	
}


int main(void) {
	
	cin >> N >> M;
	string tmp;
	
	for (int i=0; i<N; i++) {
		cin >> tmp;
		for (int j=0; j<M; j++) {
			map[i][j] = tmp[j] - '0';
		}
	}
	
	int answer = bfs();
	cout << answer;
	return 0;
}
