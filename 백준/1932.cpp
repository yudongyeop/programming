#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	
	
	int T[n+1][n+1];
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			cin >> T[i][j];
		}
	}
	
	for (int i=2; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			if (j==1) T[i][j] += T[i-1][1];
			else if (j==i) T[i][j] += T[i-1][i-1];
			else {
				T[i][j] += max(T[i-1][j], T[i-1][j-1]);
			}
		}
	}
	int max = 0;
	
	for (int i=1; i<=n; i++) {
		if (max < T[n][i]) max = T[n][i];
	}
	cout << max;
	
}
