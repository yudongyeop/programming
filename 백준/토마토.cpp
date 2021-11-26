#include <iostream>
#include <vector>
#include <queue>
#include <utility>
//BFS solution

using namespace std;

typedef pair<int, int> p;

int N,M;
int box[1002][1002];
bool visit[1002][1002];
int day = -1;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(vector<p> have) {
	queue<p> q;
	for (int i=0; i<have.size(); i++) {
		q.push(have[i]);	
	}
	
	while(!q.empty()) {
		int q_size = q.size();
		day++;
		for (int i=0; i<q_size; i++) {
			
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			visit[x][y] = true;
			//cout << "x : " << x << " y : " << y << endl;;
			
			for (int i=0; i<4; i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				
				if (nx > M || nx < 1) continue;
				if (ny > N || ny < 1) continue;
				
				if (box[nx][ny] == 0) {
					box[nx][ny] = 1;
					q.push(make_pair(nx,ny));
				}
			}	
		}
	}
}


int main(void) {
	cin >> N >> M;
	vector<p> have;
	int tmp;
	
	for (int i=1; i<=M; i++) {
		for (int j=1; j<=N; j++) {
			cin >> tmp;
			box[i][j] = tmp;
			if (box[i][j] == 1) have.push_back(make_pair(i,j));
		}
	}
		
	bfs(have);
	
	for (int i=1; i<=M; i++) {
		for (int j=1; j<=N; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << day;
	return 0;		
}
