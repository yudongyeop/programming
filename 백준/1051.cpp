#include <iostream>
#include <iostream>

using namespace std;

typedef pair<int, int> p;

int N, M;
int R[50][50];
bool Visit[50][50];
int l;
int Max;

void Input() {
	cin >> N >> M;
	string tmp;
	
	for (int i=0; i<N; i++) {
		cin >> tmp;
		for (int j=0; j<M; j++) {
			R[i][j] = tmp[j] - '0';
		}
	}
	
}

void Solution() {
	l = min(N-1, M-1);
	Max = 1;
	
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			for (int k=1; k<=l; k++) {
				if (i+k >= N || j+k >=M) continue;
				if (R[i][j] == R[i+k][j] && R[i][j+k] == R[i+k][j+k] && R[i][j] == R[i+k][j+k]) {
					Max = max((k+1)*(k+1), Max);
				} 
			}
		}
	}
	cout << Max;
}

void Solve() {
	Input();
	Solution();
}
int main(void) {
	Solve();
	return 0;
	
}
