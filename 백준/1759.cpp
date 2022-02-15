#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int L, C;

vector<char> v;

void DFS(int idx, int cnt, vector<char> s, int m, int z, int none) {	
	if (cnt == L) {
		for (int i=0; i<L; i++) {
			cout << s[i];
		}
		cout << '\n';
		return;
	}
	// 포함 
	// 모음 
	if (v[idx] == 'a' || v[idx] == 'e' || v[idx] == 'i' || v[idx] == 'o' || v[idx] == 'u') {
		if (L-2 > m) {
			s[cnt]=v[idx];
			DFS(idx+1, cnt+1, s, m+1, z, none);
		}
	}
	else {
		if (L-1 > z) {
			s[cnt]=v[idx];
			DFS(idx+1, cnt+1, s, m, z+1, none);
		}
	}
	
	if (none < C-L) {
		DFS(idx+1, cnt, s, m, z, none+1);	
	}
 	
}
int main(void) {
	cin >> L >> C;
	char a;
	
	for (int i=0; i<C; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	
	vector<char> s(L,'-');
	DFS(0, 0, s,0,0,0);	
	
	return 0;
}
