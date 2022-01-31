#include <iostream>
#include <vector>

using namespace std;


int main(void) {
	int T;
	cin >> T;
	
	vector<int> N;
	int a;
	for (int i=0; i<T; i++) {
		cin >> a;
		N.push_back(a);
	}
	
	for (int i=0; i<T; i++) {
		int n = N[i];
		
		vector<int> DP(n+1,0);
		
		DP[0] = 0;
		DP[1] = 1;
		DP[2] = 2;
		DP[3] = 4;
	 
		for (int i=4; i<=n; i++) {
			DP[i] = DP[i-1] + DP[i-2] + DP[i-3];	
		}
		
		cout << DP[n] << '\n';
	}
	
	return 0;
}
