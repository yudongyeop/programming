#include <iostream>

using namespace std;

int N;
bool Graph[100][100];
bool Visit[100];
bool Possible[100][100];

void Input() {
	cin >> N;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> Graph[i][j];
		}
	}
}

void Solution() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			for (int k=0; k<N; k++) {
				if (Graph[j][k] == 1) continue;
				if (Graph[j][i] == true && Graph[i][k] == true) Graph[j][k] = true;
			}
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (j == N-1) cout << Graph[i][j] << '\n';
			else cout << Graph[i][j] << " ";
		}
	}
}


void Solve() {
	Input();
	Solution();
}

int main(void) {
	Solve();
	return 0;
}
