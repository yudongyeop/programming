#include <iostream>

using namespace std;

int T, n;
int arr[2][100000];

int main(void) {
	cin >> T;
	int answer[T];
	
	for (int t=0; t<T; t++) {
		cin >> n;
		
		//INPUT
		for (int a=0; a<2; a++) {
			for (int b=1; b<=n; b++) {
				cin >> arr[a][b];
			}
		}
		
		int DP[2][n+1];
		
		DP[0][0] = 0;
		DP[1][0] = 0;
		DP[0][1] = arr[0][1];
		DP[1][1] = arr[1][1];
		
		for (int i=2; i<=n; i++) {
			DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + arr[0][i];
			DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + arr[1][i];
		}
		
		answer[t] = max(DP[0][n], DP[1][n]);
		
	}
	
	for (int i=0; i<T; i++) {
		cout << answer[i] << '\n';
	}
	
	return 0;
}
