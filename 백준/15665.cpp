#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool Visit[10001];
vector<int> v;


void DFS(int idx, vector<int> tmp) {
	
	if (idx == M) {
		for (int i=0; i<M; i++) {
			cout << tmp[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i=0; i<v.size(); i++) {
		tmp[idx] = v[i];
		DFS(idx+1, tmp);
	}
}

int main(void) {
	cin >> N >> M;
	int a;
	
	for (int i=0; i<N; i++) {
		cin >> a;
		if (Visit[a]) continue;
		
		Visit[a] = true;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	
	vector<int> tmp(N,0);
	DFS(0,tmp);
	
	
	
	
	return 0;
	
}
