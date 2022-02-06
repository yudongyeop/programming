#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	int dp[k+1] = {0,};
	int coins[n]; 
	
	for (int i=0; i<n; i++) {
		cin >> coins[i];
	}
	sort(coins, coins+n-1);
	dp[0] = 1;
	
	for (int i=0; i<n; i++) {
		for (int j=coins[i]; j<=k; j++) {
			dp[j] += dp[j-coins[i]];
		}
	}
	cout << dp[k];
	

	
	return 0;
	
}
