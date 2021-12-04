#include <iostream>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

int P[50][50];
bool visit[50][50];

int N,L,R;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

typedef pair<int,int> p;

vector<p> com_list;

void Input(void) {
	cin >> N >> L >> R;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> P[i][j];
		}
	}
}

bool BFS(int i, int j) {
	bool stop = false;
	queue<p> q;
	int tmp1, tmp2;
	tmp1 = i;
	tmp2 = j;
	q.push(make_pair(i,j));
	visit[i][j] = true;
	com_list.push_back(make_pair(i,j));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		//cout << "x : " << x << " y : " << y << endl;
		q.pop();
		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			int diff = P[x][y] - P[nx][ny];
			if (diff < 0) diff = -diff;
			if (diff <= R && diff >= L && visit[nx][ny] == false) {
				q.push(make_pair(nx,ny));
				visit[nx][ny] = true;
				com_list.push_back(make_pair(nx,ny));
			}
		}
	}
	
	int sum = 0;
	int cnt = com_list.size();
	if (cnt > 1) stop = true;
	
	for (int i=0; i<com_list.size(); i++) {
		sum += P[com_list[i].first][com_list[i].second];
	}
	int new_p = sum/cnt;
	
	for (int i=0; i<com_list.size(); i++) {
		P[com_list[i].first][com_list[i].second] = new_p;
	}
	
	com_list.clear();
	
	return stop;	
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	
	int day = 0;
	while (1) {
		bool stop = false;
		bool End = true;
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (visit[i][j] == false) {
					stop = BFS(i,j);
					if(stop) End = false; 
				}
			}
		}
		if (End) {
			cout << day;
			return 0;
		}
		day++;
		memset(visit,0,sizeof(visit));
	}
}
