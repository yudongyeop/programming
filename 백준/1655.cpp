#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

priority_queue<int, vector<int>, less<int>> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

vector<int> answer;


int main(void) {
	cin >> N;
	int a;
	
	for (int i=0; i<N; i++) {
		cin >> a;
		if (max_pq.size() <= min_pq.size()) {
			max_pq.push(a);
		}
		else min_pq.push(a);
		if (max_pq.size() >= 1 && min_pq.size() >= 1) {
			if (max_pq.top() > min_pq.top()) {
				int tmp1 = max_pq.top();
				max_pq.pop();
				int tmp2 = min_pq.top();
				min_pq.pop();
				max_pq.push(tmp2);
				min_pq.push(tmp1);
			}	
		}
		
		
		answer.push_back(max_pq.top());
	}
	
	for (int i=0; i<answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	
	return 0;
		
}
