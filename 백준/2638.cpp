#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> p;

int N, M;
int Map[100][100];
bool Visit[100][100];
int Check[100][100];
int answer = 0;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

void Input() {
	cin >> N >> M;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			
			cin >> Map[i][j];
		}
	}
}

bool Finish() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (Map[i][j] == 1) return false;
		}
	}
	return true;
}

void BFS() {
	queue<p> q;
	int x = 0;
	int y = 0;
	q.push(make_pair(x,y));
	Visit[x][y] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
	
			if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
			
			if (Visit[nx][ny] == false && Map[nx][ny] == 0) {
				Visit[nx][ny] = true;
				q.push(make_pair(nx,ny));
			}
			else if (Visit[nx][ny] == false && Map[nx][ny] == 1) {
				Check[nx][ny]++;
			}
		}
	}
	
	memset(Visit,0,sizeof(Visit));
	//cout << "hour : " << answer << endl;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (Check[i][j] >= 2) {
				//cout << " i : " << i << " j : " << j << endl;
				Map[i][j] = 0;
			}
		}
	}
	memset(Check,0,sizeof(Check));		
}

void Solve() {
	while (!Finish()) {
		answer++;
		BFS();
	}
	cout << answer;	
}
  
int main(void) {
	Input();
	Solve();
	return 0;
}
