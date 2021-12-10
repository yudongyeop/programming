#include <iostream>
#include <vector>

using namespace std;

int Dice[6]; 
int Map[20][20];
int Cmd[1000];

int N,M,K;
int x,y;

int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};

void Input() {
	cin >> N >> M >> x >> y >> K;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i=0; i<K; i++) {
		cin >> Cmd[i];
	}
}

void Solve() {
	
	for (int i=0; i<K; i++) {
		
		int d = Cmd[i];
		
		int nx = x+dx[d];
		int ny = y+dy[d];
		
		if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
		
		x+=dx[d];
		y+=dy[d];
		
 		int d0, d1, d2, d3, d4, d5;
 		d0 = Dice[0];
		d1 = Dice[1];
		d2 = Dice[2];
 	    d3 = Dice[3];
		d4 = Dice[4];
		d5 = Dice[5];

		switch(d) {
			
			case 1:  //east
				Dice[0] = d3;
        		Dice[3] = d5;
        		Dice[5] = d2;
        		Dice[2] = d0;
				break;
			
			case 2: //west
				Dice[3] = d0;
				Dice[5] = d3;
				Dice[2] = d5;
				Dice[0] = d2;
				break;
			
			case 3: //north
				Dice[0] = d4;
				Dice[1] = d0;
				Dice[5] = d1;
				Dice[4] = d5;
				break;
			
			case 4: //south
				Dice[4] = d0;
				Dice[0] = d1;
				Dice[1] = d5;
				Dice[5] = d4;
				break;
		}
		
		if (Map[x][y] == 0) {
			Map[x][y] = Dice[5];
		}
		else {
			Dice[5] = Map[x][y];
			Map[x][y] = 0;
		}
		cout << Dice[0] << '\n';	
	}
	
}


int main(void) {
	Input();
	Solve();
	return 0;
}
