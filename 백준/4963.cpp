#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> p;

int w, h;

bool map[51][51];
bool visit[51][51];
vector<int> ans;

int dx[] = {-1,0,1,0,1,-1,1,-1};
int dy[] = {0,1,0,-1,1,1,-1,-1};

void BFS(int sx, int sy) {
	queue<p> q;
	q.push(make_pair(sx,sy));
	visit[sx][sy] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i=0; i<8; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			
			if (!visit[nx][ny] && map[nx][ny] == 1) {
				visit[nx][ny] = true;
				q.push(make_pair(nx,ny));
			}

		}
	}			
	
}

int main(void) {
	
	
	while (1) {
		cin >> w >> h;
		int n = 0;
		
		if (w == 0 && h == 0) {
			for (int i=0; i<ans.size(); i++) {
				cout << ans[i] << '\n';
			}
			break;
		}
		
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				cin >> map[i][j];
			}
		}
		
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				if (!visit[i][j] && map[i][j] == 1) {
					BFS(i,j);
					n++;
				}
			}
		}
		ans.push_back(n);
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit)); 
	}
	
	return 0;
}
