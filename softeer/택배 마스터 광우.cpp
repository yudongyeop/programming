#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M, K;
vector<int> rail;
int Answer = INT_MAX;

void Input() {
	cin >> N >> M >> K;
	
	int a;
	for (int i=0; i<N; i++) {
		cin >> a;
		rail.push_back(a);
	}
}

int GetWeight(vector<int> rail) {
	
	int cnt = 0;
	int i = 0;
	int tmp = 0;
	int result = 0;
	
	while (cnt < K) {
		if (tmp+rail[i] <= M) {
			tmp+= rail[i];
			result+= rail[i];
			i = (i+1)%N;
		}
		
		else {
			cnt++;
			tmp = 0;
		}
	}
	return result;
}


void Solution() {
	sort(rail.begin(), rail.end());
	
	do {
		int tmp = GetWeight(rail);
		if (Answer > tmp) Answer = tmp; 
	} while (next_permutation(rail.begin(), rail.end()));
	
	cout << Answer;
}


void Solve() {
	Input();
	Solution();
}


int main(void) {
	Solve();
	return 0;
}
