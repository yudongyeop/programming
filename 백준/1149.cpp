#include <iostream>

using namespace std;


int main(void) {
	//0-1 knapsack??
	int n;
	cin >> n;
	
	int dp[n+1][4];
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=3; j++) {
			cin >> dp[i][j];
		}
	}
	
	for (int i=2; i<=n; i++) {
		for (int j=1; j<=3; j++) {
			if (j == 1) {
				dp[i][j] += min(dp[i-1][2], dp[i-1][3]);
			}
			else if (j == 2) {
				dp[i][j] += min(dp[i-1][1], dp[i-1][3]);
			}
			else if (j == 3) {
				dp[i][j] += min(dp[i-1][1], dp[i-1][2]);
			}
		}
	} 
	 
	int tmp = min(dp[n][1], dp[n][2]);
	int answer = min(tmp,dp[n][3]);	
	
	cout << answer;
	return 0;
}
