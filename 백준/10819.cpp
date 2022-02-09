#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
	
	int n;
	cin >> n;
	vector<int> v;
	int ans = 0;
	
	int a;
	for (int i=0; i<n; i++) {
		cin >> a;
		v.push_back(a);
	}	
	sort(v.begin(), v.end());
	
	do {
		int sum = 0;
		for (int i=0; i<=n-2; i++) sum+=abs(v[i]-v[i+1]);
		ans = max(ans, sum);
	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans;
	
	return 0;	
}
