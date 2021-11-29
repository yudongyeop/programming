#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> gift;
vector<int> wish;
priority_queue<int, vector<int>, less<int>> pq; //pq는 heap 을 사용하므로 시간 복잡도가 logN이다. 
//어떤 자료구조에 원소들을 모두 정렬하는것이 아니라 max값이나 min값을 찾을 때 효율적이다. 
int main(void) {
	cin >> N >> M;
	int tmp;
	for (int i=0; i<N; i++) {
		cin >> tmp;
		pq.push(tmp);
	}
	
	for (int i=0; i<M; i++) {
		cin >> tmp;
		wish.push_back(tmp);
	}
	
	
	for (int i=0; i<M; i++) {
		int max = pq.top();
		pq.pop();
		int get = max - wish[i];
		pq.push(get);
		
		if (get < 0) {
			cout << 0;
			return 0;
		}
	}
	
	cout << 1;
	return 0;
}
