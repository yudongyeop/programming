#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N;
	map<int,int> m;
	vector<int> v;
	vector<int> answer;
	int tmp;
	for (int i=0; i<N; i++) {
		cin >> tmp;
		m[tmp]++;
	}
	cin >> M;
	for (int i=0; i<M; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	
	for (int i=0; i<M; i++) {
		answer.push_back(m[v[i]]);
	}
	
	for (int i=0; i<answer.size(); i++) {
		cout << answer[i] << " ";
	}
	
	return 0;
}
