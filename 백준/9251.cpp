#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s1;
	string s2;
	
	cin >> s1 >> s2;
	int size1 = s1.size();
	int size2 = s2.size();
	
	int DP[size2+1][size1+1];
	
	for (int i=0; i<=size2; i++) {
		for (int j=0; j<=size1; j++) {
			DP[i][j] = 0;
		}
	}
	
	for (int i=0; i<size2; i++) {
		for (int j=0; j<size1; j++) {
			if (s2[i] == s1[j]) {
				DP[i+1][j+1] = DP[i][j]+1;
			}
			else {
				DP[i+1][j+1] = max(DP[i][j+1], DP[i+1][j]);
			}
		}
	}
	cout << DP[size2][size1];
	return 0;

}
