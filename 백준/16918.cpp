#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> p;

char Map[200][200];
int R, C, N;


int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int time = 1;

void Print() {

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cout << Map[i][j];
		}
		cout << '\n';
	}
}

void Input() {
	cin >> R >> C >> N;
	string tmp;
	
	for (int i=0; i<R; i++) {
		cin >> tmp;
		for (int j=0; j<C; j++) {
			Map[i][j] = tmp[j];
		}
	}
}



void Solution() {
	
	if (N % 2 == 0) {
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				Map[i][j] = 'O';
			}
		}
		Print();
		return;
	}

	// 1 3 5 7
	while (time != N) {
		
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				if (Map[i][j] == 'O') {
					Map[i][j] = 'a';
					for (int k=0; k<4; k++) {
						int ni = i+dx[k];
						int nj = j+dy[k];
						
						if (ni < 0 || ni >=R || nj < 0 || nj >= C || Map[ni][nj] == 'O') continue;
							Map[ni][nj] = 'a';
					}
				}
			}
		}
		
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				if (Map[i][j] == '.') Map[i][j] = 'O';
			}
		}
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				if (Map[i][j] == 'a') Map[i][j] = '.';
			}
		}
		time+=2;
	}
	
	Print();
	
}

void Solve() {
	Input();
	Solution();
}
int main(void) {
	Solve();
	return 0;
}
