#include <iostream>
#include <vector>
#include <queue>
#include <utility>
//BFS solution

using namespace std;

typedef pair<int, int> p;

int N,M,H;
int box[10010][102];
bool visit[10010][102];
int day = -1;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ud[] = {M,-M};

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
			int num_box = ((x-1)/M)+1;
			
			q.pop();
			visit[x][y] = true;
			//cout << "x : " << x << " y : " << y << endl;
			
			for (int i=0; i<2; i++) {
				int nud = x+ud[i];
				//cout << "nud : " << nud << endl;
				if (nud < 1 || nud > H*M) continue;
				
				if (box[nud][y] == 0) {
					box[nud][y] = 1;
					q.push(make_pair(nud,y));
				}
			}  
			for (int i=0; i<4; i++) { //µ¿¼­³²ºÏ 
				int nx = x+dx[i];
				int ny = y+dy[i];
				
				if (nx > num_box*M || nx <= (num_box-1)*M) continue;
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
	cin >> N >> M >> H;
	vector<p> have;
	int tmp;
	ud[0] = M;
	ud[1] = -M;
	for (int i=1; i<=M*H; i++) {
		for (int j=1; j<=N; j++) {
			cin >> tmp;
			box[i][j] = tmp;
			if (box[i][j] == 1) {
				have.push_back(make_pair(i,j));	
				//cout << "x : " << i << " y : " << j << endl;
			}
			
		}
	}
		
	bfs(have);
	
	for (int i=1; i<=M*H; i++) {
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
