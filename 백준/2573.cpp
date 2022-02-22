#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int,int> p;

int n,m;
int map[300][300];
bool visit[300][300];
bool visit2[300][300];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

vector<p> ice;

void Input() {
	cin >> n >> m;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				ice.push_back(make_pair(i,j));
			}
		}
	}
}

void Melting() {
	
	for (int i=0; i<ice.size(); i++) {
		int x = ice[i].first;
		int y =  ice[i].second;
		visit[x][y] = true;
		
		for (int j=0; j<4; j++) {
			int nx = x+dx[j];
			int ny = y+dy[j];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if (map[nx][ny] == 0 && !visit[nx][ny]) {
				map[x][y]--;
				
				if (map[x][y] == 0) {
					ice.erase(ice.begin()+i);
					i--;
					break;
				}
			}
		}	
	}
}

void BFS(int sx, int sy) {
	queue<p> q;
	q.push(make_pair(sx,sy));
	visit2[sx][sy] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if (!visit2[nx][ny] && map[nx][ny] != 0) {
				visit2[nx][ny] = true;
				q.push(make_pair(nx,ny));
			}
		}
	}	
}

int Check() {
	int result = 0;
	memset(visit,0,sizeof(visit));
	
	for (int i=0; i<ice.size(); i++) {
		if (!visit2[ice[i].first][ice[i].second]) {
			result++;
			BFS(ice[i].first, ice[i].second);
		}
	}
	memset(visit2,0,sizeof(visit2));
	
	return result;
}


void Solution() {
	int ans = 0;
	
	while (Check() < 2) {
		ans++;
		Melting();
		bool stop = true;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (map[i][j] != 0) {
					stop = false;
				}
			}
		}
		if (stop) {
			cout << "0";
			return;
		}
		memset(visit,0,sizeof(visit));
	}
	
	cout << ans;
}

void Solve() {
	Input();
	Solution();
}

int main(void) {
	
	Solve();
	return 0;
}
