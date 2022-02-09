#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef pair<int,int> p;

int n;
char map[100][100];
bool visit[100][100];
bool visit2[100][100];

int ans1, ans2;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


void Input() {
	cin >> n;
	string tmp;
	
	for (int i=0; i<n; i++) {
		cin >> tmp;
		for (int j=0; j<n; j++) {
			map[i][j] = tmp[j];
		}
	}
}

void BFS(int d, int sx, int sy) {
	queue<p> q;
	q.push(make_pair(sx,sy));
	if (d == 0) {
		visit[sx][sy] = true;
		
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			//cout << map[x][y] << endl; 
			
			for (int i=0; i<4; i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				
				if (map[x][y] == map[nx][ny] && !visit[nx][ny]) {
					q.push(make_pair(nx,ny));
					visit[nx][ny] = true;
				}
				
			} 
		}
	}
	
	else if (d == 1) {
		visit2[sx][sy] = true;
		
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for (int i=0; i<4; i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				
				if (!visit2[nx][ny]) {
					if (map[nx][ny] == map[x][y] || (map[nx][ny] == 'G' && map[x][y] == 'R') || (map[nx][ny] == 'R' && map[x][y] == 'G')) {
						q.push(make_pair(nx,ny));
						visit2[nx][ny] = true;
					}	
				}
				
			} 
		}
	}
}

void Solution() {
	//정상 
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (!visit[i][j]) {
				BFS(0,i,j);
				ans1++;	
			}
		}
	}
	
	//적록색약 
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (!visit2[i][j]) {
				BFS(1,i,j);
				ans2++;	
			}
		}
	}
	cout << ans1 << " " << ans2;
}

void Solve() {
	Input();
	Solution();
}

int main(void) {
	Solve();
	return 0;
}
