#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int R, C;
char Lake[1500][1500];
bool Visit[1500][1500];
int Day;
bool CanMeet;
queue<p> Q;
queue<p> NQ;
queue<p> S_Q;
queue<p> S_NQ;

int Swan_Pos_x, Swan_Pos_y;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void Input() {
	CanMeet = false;
	cin >> R >> C;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> Lake[i][j];
			if (Lake[i][j]  != 'X') Q.push(make_pair(i,j));
			if (Lake[i][j] == 'L') {
				Swan_Pos_x = i;
				Swan_Pos_y = j;
			}
		}
	}
}

void BFS() {
	
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		
		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			
			if (Lake[nx][ny] == 'X') {
				Lake[nx][ny] = '.';
				NQ.push(make_pair(nx,ny));
			}
		}
	}

}

void S_BFS() {
	
	while (!S_Q.empty() && !CanMeet) {
		int x = S_Q.front().first;
		int y = S_Q.front().second;
		S_Q.pop();
		
		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
			
				if (!Visit[nx][ny]) {
				
					
					if (Lake[nx][ny] == '.') {
						Visit[nx][ny] = true;
						S_Q.push(make_pair(nx,ny));
						
					}	
				
					else if (Lake[nx][ny] == 'L') {
						Visit[nx][ny] = true;
						CanMeet = true;
						break;
					}
					else if (Lake[nx][ny] == 'X') {
						Visit[nx][ny] = true;
						S_NQ.push(make_pair(nx,ny));
					}
				}
			}
		}
	}
}

void Solve() {
	
	S_Q.push(make_pair(Swan_Pos_x, Swan_Pos_y));
	Visit[Swan_Pos_x][Swan_Pos_y] = true;
		
	while (!CanMeet) {
		S_BFS();
		
		if (!CanMeet) {
			BFS();
			Q = NQ;
	        S_Q = S_NQ;
	 
	        while (NQ.empty() == 0) NQ.pop();
	        while (S_NQ.empty() == 0) S_NQ.pop();
	        Day++;
		}

	}
	cout << Day;
}

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	Input();
	Solve();
	return 0;
}
