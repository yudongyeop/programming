#include <iostream>
#include <queue>


using namespace std;

typedef pair<int,int> p;
typedef pair<p,p> pp;

char Map[100][100];
bool Visit[100][100];

int W, H;

int start_x, start_y;

int dx[] = {0,0,1,-1}; // µ¿(0), ¼­(1), ³²(2), ºÏ(3) 
int dy[] = {1,-1,0,0};

void Input() {
	
	cin >> W >> H;
	
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'C') {
				start_x = i;
				start_y = j;
			}
		}
	}
}

void BFS() {
	queue<pp> q;
	q.push(make_pair(make_pair(start_x,start_y), make_pair(-1,0)));
	Visit[start_x][start_y] = true;
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		
		int di = q.front().second.first;
		int n = q.front().second.second;
		
		cout << " x : " <<  x << " y : " << y << " n : " << n << endl;
		if (di != -1 && Map[x][y] == 'C') {
			cout << n-1;
			return;
		}
		q.pop();
		
		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			
			if (!Visit[nx][ny] && Map[nx][ny] != '*') {
				if (di != i && di != -1) {
					Visit[nx][ny] = true;
					q.push(make_pair(make_pair(nx,ny), make_pair(i,n+1)));
				}
				else if (di == i || di == -1) {
					Visit[nx][ny] = true;
					q.push(make_pair(make_pair(nx,ny), make_pair(i,n)));
				}
			}
		} 	
	}
}

int main(void) {
	Input();
	BFS();
	return 0;
}
