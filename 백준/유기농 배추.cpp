#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T,M,N,K;

int grd[60][60];
bool visit[60][60];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x, int y) {
	visit[x][y] = true;
	
	for (int i=0; i<4; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if (grd[nx][ny] == 1 && visit[nx][ny] == false) dfs(nx,ny);
	}
		
}

int main(void) {
	cin >> T; 
	vector<int> v_answer;
	for (int i=0; i<T; i++) {
		cin >> N >> M >> K;
		int answer = 0;
		memset(grd, 0, sizeof(grd));
		memset(visit, 0, sizeof(visit));
		for (int i=0; i<K; i++) {
			int x;
			int y;
			cin >> x >> y;
			grd[x+1][y+1] = 1;
		}
	
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=M; j++) {
				if (grd[i][j] == 1 && visit[i][j] == false) {
					dfs(i,j);
					//cout << " x : " << i << " y : " << j << endl;
					answer++;
				}
			}
		}
		
		v_answer.push_back(answer);
	}
	for (int i=0; i<v_answer.size(); i++) cout << v_answer[i] << '\n';			
}
