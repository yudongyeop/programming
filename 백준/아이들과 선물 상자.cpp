#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> gift;
vector<int> wish;
priority_queue<int, vector<int>, less<int>> pq; //pq�� heap �� ����ϹǷ� �ð� ���⵵�� logN�̴�. 
//� �ڷᱸ���� ���ҵ��� ��� �����ϴ°��� �ƴ϶� max���̳� min���� ã�� �� ȿ�����̴�. 
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
