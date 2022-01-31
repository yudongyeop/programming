#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> p;

int N;
int Map[101][101];
int R;
int Ans;

bool Visit[101][101];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void BFS(int sx, int sy) {
	queue<p> q;
	q.push(make_pair(sx,sy));
	Visit[sx][sy] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			
			if (!Visit[nx][ny] && Map[nx][ny] > R) {
				Visit[nx][ny] = true;
				q.push(make_pair(nx,ny));
			}
		}
	}		
}

int main(void) {
	cin >> N;
	int min = 101;
	int max = 0;
	
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] < min) min = Map[i][j];
			if (Map[i][j] > max) max = Map[i][j]; 
		}
	}
	
	for (int i = 0; i<= max; i++) {
		R = i;
		int cnt = 0;	
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (!Visit[i][j] && Map[i][j] > R) {
					BFS(i,j);
					cnt++;
				}
			}
		}
		memset(Visit,0,sizeof(Visit));
		if (Ans < cnt) Ans = cnt;
	}
	cout << Ans;
	return 0;	
}
