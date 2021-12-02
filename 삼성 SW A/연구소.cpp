#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
 
using namespace std;

int N, M;
int lab[8][8];
int tmp_lab[8][8];
int Max;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

typedef pair<int,int> p;

vector<p> Empty;
vector<p> virus;
vector<p> wall_list;


void Input() {
	cin >> N >> M;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> lab[i][j];
		}
	} // input lab
	
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (lab[i][j]==2) virus.push_back(make_pair(i,j)); 
		}
	} // input virus space
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (lab[i][j] == 0) Empty.push_back(make_pair(i,j));
		}
	} // input empty space
}

int BFS() {
	
	int safe = 0;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			tmp_lab[i][j] = lab[i][j];
		}
	}
	
	for (int i=0; i<wall_list.size(); i++) {
		int x = wall_list[i].first;
		int y = wall_list[i].second;
		
		tmp_lab[x][y] = 1;
	}

	queue<p> q;
	
	for (int i=0; i<virus.size(); i++) {
		q.push(virus[i]);
	}
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			
			if (tmp_lab[nx][ny] == 0) {
				q.push(make_pair(nx,ny));
				tmp_lab[nx][ny] = 2;
			}
		}
	}
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (tmp_lab[i][j] == 0) {
				safe++;	
			}
		}
	}
	memset(tmp_lab,0,sizeof(tmp_lab));
	return safe;
}

void Make3Wall() {

	vector<int> c;
	
	for (int i=0; i<Empty.size(); i++) {
		if(i<3) c.push_back(1);
		else c.push_back(0);
	}
	
	do {
		for (int i=0; i<Empty.size(); i++) {
			if (c[i] == 1) {
				wall_list.push_back(Empty[i]);		
			}
		}
		int tmp = BFS();
		if (Max <= tmp) Max = tmp;
		wall_list.clear();
		
	} while (prev_permutation(c.begin(), c.end()));
	
}

int main(void) {
	Input();
	Make3Wall();
	cout << Max;
	return 0;
}
