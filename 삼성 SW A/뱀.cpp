#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> p;

int N, K, L;
int Board[100][100]; // 0 empty, 1 apple, 2 body
int Move[10001];
queue<p> Length;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void Input() {
	cin >> N >> K;
	int a, b;
	char c; // L -> Left , D -> Right
	for (int i=0; i<K; i++) {
		cin >> a >> b;
		Board[a-1][b-1] = 1; 	
	}
	
	cin >> L; 
	for (int i=0; i<L; i++) {
		cin >> b >> c;
		if (c == 'L') Move[b] = -1;
		if (c == 'D') Move[b] = 1;
	}
	
}

void Solve() {
	
	int time = 0;
	int d = 0; // current direction, right
	int x = 0;
	int y = 0;
	
	Board[x][y] = 2;
	Length.push(make_pair(x,y));
	  
	while(1) {
		
		time++;
		x += dx[d];
		y += dy[d];
		
		Length.push(make_pair(x,y));
		
		if (x < 0 || x >= N || y < 0 || y >= N) break;
		
		else if (Board[x][y] == 2) break;
		
		else if (Board[x][y] == 1) Board[x][y] = 2;
		
		else if (Board[x][y] == 0) {
			int rm_x = Length.front().first;
			int rm_y = Length.front().second;
			Length.pop();
			Board[rm_x][rm_y] = 0;
			Board[x][y] = 2;
		}
		
		d += Move[time];
		
		if (d < 0) d += 4;
		else if (d > 3) d -= 4;
	}
	cout << time;
}

int main(void) {
	Input();
	Solve();
	
	return 0;
}
