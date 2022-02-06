#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int coin[101];
int dp[10001];

int main(void) {
	cin >> n >> k;
	
	for (int i=0; i<=k; i++) {
		dp[i] = k+1;
	}
	
	for (int i=0; i<n; i++) {
		cin >> coin[i];
	}

	dp[0] = 0;
	for (int i=0; i<n; i++) {
		for (int j=coin[i]; j<=k; j++) {
			dp[j] = min(dp[j], 1+dp[j-coin[i]]);		
		}
	}
	
	if (dp[k] == k+1) cout << -1;
	else cout << dp[k];
	return 0;
}
