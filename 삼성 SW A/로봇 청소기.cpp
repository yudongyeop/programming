#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N,M;
int room[50][50];
int clean[50][50];
int answer = 0;

int start_x;
int start_y;
int start_d;

// state north 0

// state east 1

// state south 2

// state west 3

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int bx[4] = {1,0,-1,0};
int by[4] = {0,-1,0,1};

typedef tuple<int,int,int> t;

void Input() {
	cin >> N >> M;
	cin >> start_x >> start_y >> start_d;
		
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> room[i][j];
		}
	}
	

}

void Solution() {
	queue<t> q;
	q.push(make_tuple(start_x, start_y, start_d));
	clean[start_x][start_y] = true;
	answer++;
	int cnt = 0;
	
	while(!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int d = get<2>(q.front());
		q.pop();
		int nx = x+dx[d];
		int ny = y+dy[d];
		int nd = d-1;
		if (nd < 0) nd+= 4;
			
		if (room[nx][ny] == 0 && clean[nx][ny] == false) {
			clean[nx][ny] = true;
			answer++;
			q.push(make_tuple(nx,ny,nd));
			cnt = 0;
		}
		
		else if (room[nx][ny] == 1 || clean[nx][ny] == true) {
			if (cnt == 4) {
				cnt = 0;
				int b_x = x + bx[d];
				int b_y = y + by[d];
			
				if (b_x < 0 || b_x >= N || b_y < 0 || b_y >= M) continue;
			
				if (room[b_x][b_y] == 1) {
					break;
				}
			
				q.push(make_tuple(b_x,b_y,d));
				continue; 	
			}
			q.push(make_tuple(x,y,nd));
			cnt++;
		}
		
	}	
				
}
	


int main(void) {
	Input();
	Solution();	
	cout << answer;
	
	
	
	return 0;
}
