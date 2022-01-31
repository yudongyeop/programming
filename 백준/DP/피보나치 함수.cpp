#include <iostream>
#include <vector>

using namespace std;

vector<int> N;

int main(void) {
	int T;
	cin >> T;
	int a;
	for (int i=0; i<T; i++) {
		cin >> a;
		N.push_back(a);
	}
	for (int i=0; i<T; i++) {
		int n = N[i];
		vector<int> DP(n+1,0);
		
		if (n == 0) {
			cout << 1 << " " << 0 << endl;
			continue;
		}
		
		if (n == 1) {
			cout << 0 << " " << 1 << endl;
			continue;
		}
		DP[n] = 1;
		
		for (int i=n; i>=2; i--) {
			DP[i-1] += DP[i];
			DP[i-2] += DP[i];  	
		}
		cout << DP[0] << " " << DP[1] << endl;		
	}
	
	
	
	return 0;	
}
