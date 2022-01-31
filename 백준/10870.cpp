#include <iostream>

using namespace std;

int DP[20];

int main(void) {
	int n;
	cin >> n;
	
	DP[0] = 0;
	DP[1] = 1;
	
	for (int i=2; i<=n; i++) DP[i] = DP[i-2] + DP[i-1];
	cout << DP[n];
	
	return 0;
}
