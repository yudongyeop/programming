#include <iostream>
#include <vector>

using namespace std;

vector<int> N;

vector<vector<int>> v;
int ans[13];

void Input() {
	
	while (1) {
		int a;
		cin >> a;
		if (a == 0) break;
		int size = a;
		N.push_back(a);
		vector<int> tmp;
		v.push_back(tmp);
		for (int i=0; i<size; i++) {
			cin >> a;
			v[v.size()-1].push_back(a);
		}
	}
	
	
}

void DFS(int s, int idx, int cnt, vector<int> result, int no) {
	
	if (result.size() == 6) {
		for (int i=0; i<result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	if (no > N[s]-6) return;	
	
	vector<int> tmp;
	tmp = result;
	
	result.push_back(v[s][idx]);
	DFS(s, idx+1, cnt+1, result, no);
	
	
	DFS(s, idx+1, cnt, tmp, no+1); 
	
}

void Solution() {
	vector<int> rst;
	for (int i=0; i<v.size(); i++) {
		DFS(i,0,0,rst,0);
		cout << '\n';
	}
}

void Solve() {
	Input();
	Solution();
	
}
int main(void) {
	Solve();
	return 0;
}
