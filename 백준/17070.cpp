#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int,int,int> t;


int N;
bool Map[16][16];
int Ans;

void Input() {
	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> Map[i][j];
		}
	}
}

 
void BFS() {
	queue<t> q;
	q.push(make_tuple(0,1,0));
	
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int s = get<2>(q.front());
		q.pop();
		if (x == N-1 && y == N-1) Ans++;
		
		if(s == 0) {
			
			if (y+1 < N && !Map[x][y+1]) {
				q.push(make_tuple(x,y+1,0));
			}
			
			if (x+1 < N && y+1 < N && !Map[x+1][y] && !Map[x][y+1] && !Map[x+1][y+1]) {
				q.push(make_tuple(x+1,y+1,2));
			}
		}
		
		else if (s == 1) {
			
			if (x+1 < N && !Map[x+1][y]) {
				q.push(make_tuple(x+1,y,1));
			}
			
			if (x+1 < N && y+1 < N && !Map[x+1][y] && !Map[x][y+1] && !Map[x+1][y+1]) {
				q.push(make_tuple(x+1,y+1,2));
			}
		}
		
		else if (s == 2) {
			
			if (x+1 < N && !Map[x+1][y]) {
				q.push(make_tuple(x+1,y,1));
			}
			
			if (y+1 < N && !Map[x][y+1]) {
				q.push(make_tuple(x,y+1,0));
			}
			
			if (x+1 < N && y+1 < N && !Map[x+1][y] && !Map[x][y+1] && !Map[x+1][y+1]) {
				q.push(make_tuple(x+1,y+1,2));
			}
		}
		
	}
	
}

void Solution() {
	BFS();
	cout << Ans;
}
void Solve() {
	Input();
	Solution();
}

int main(void) {
	
	Solve();
	
	return 0;
}
