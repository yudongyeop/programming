#include <iostream>
#include <algorithm>


using namespace std;

int num[20];
long long Max = -1000000001;
long long Min = 1000000001;
 
int N;

void dfs(int sum, int sub, int mul, int div, int cnt, long long rst) {
	if(cnt == N) {
		Max = max(Max, rst);
		Min = min(Min, rst);
	}
	else {
	if(sum > 0) dfs(sum-1, sub, mul, div, cnt+1, rst+num[cnt]);
	if(sub > 0) dfs(sum, sub-1, mul, div, cnt+1, rst-num[cnt]);
	if(mul > 0) dfs(sum, sub, mul-1, div, cnt+1, rst*num[cnt]);
	if(div > 0) dfs(sum, sub, mul, div-1, cnt+1, rst/num[cnt]);
	}
	
}



int main(void) {
	int n;
	cin >> n;
	N = n;
	for(int i=0; i<n; i++) cin >> num[i];
	int sum, sub, mul, div;
	cin >> sum >> sub >> mul >> div;
	dfs(sum, sub, mul, div, 1, num[0]);
	
	if(Max >= 1000000000) cout << "1000000000" << endl;
	else cout << Max << endl;
	
	if(Min <= -1000000000) cout << "-1000000000" << endl;
	else cout << Min << endl;
	
	return 0;
}
