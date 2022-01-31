#include <iostream>

using namespace std;

int N, K;
char DP[401][401];


int main(void) {
	cin >> N >> K;
	
	for (int i=0; i<=N; i++) {
		DP[i][0] = 1;
	}
	
	for (int i=0; i<=K; i++) {
		DP[i][i] = 1;
	}
	
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=K; j++) {
			DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
		}
	}
	
	cout << DP[N][K]%1000000007;
		
	
}
