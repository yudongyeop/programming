#include <iostream>
#include <vector>
#include <map>


using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M,tmp;
	cin >> N;
	map<int,bool> m;
	vector<int> answer;
	
	for (int i=0; i<N; i++) {
		cin >> tmp;
		m[tmp] = 1;
	}
	cin >> M;
	for (int i=0; i<M; i++) {
		cin >> tmp;
		answer.push_back(m[tmp]);
	}
	for (int i=0; i<answer.size(); i++) cout << answer[i] << " ";
	
	
	return 0;	
}
 
