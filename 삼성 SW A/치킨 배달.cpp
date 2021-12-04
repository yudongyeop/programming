#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef pair<int,int> p;

int N,M;

int city[50][50];

vector<p> home;
vector<p> chicken;

int answer = 100000;

void Input() {
	cin >> N >> M;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) home.push_back(make_pair(i,j));
			else if (city[i][j] == 2) chicken.push_back(make_pair(i,j));
		}
	} // init city, home, chicken
}

void Solution(vector<p> limit_chicken) {
	int sum = 0;
	for (int i=0; i<home.size(); i++) {
		int x = home[i].first;
		int y = home[i].second;
		int Min = 101;
		for (int j=0; j<limit_chicken.size(); j++) {
			int x2 = limit_chicken[j].first;
			int y2 = limit_chicken[j].second;
			
			int dst = abs(x-x2) + abs(y-y2);
			if (Min >= dst) Min = dst;
		}
		sum+= Min;
	}
	if (answer >= sum) answer = sum;	
}

void Combination() {
	vector<int> c(chicken.size(),0);
	vector<p> limit_chicken;
	
	for (int i=0; i<M; i++) c[i] = 1;
	
	do {
		for (int i=0; i<c.size(); i++) {
			if (c[i] == 1) limit_chicken.push_back(chicken[i]);
		}
		Solution(limit_chicken);
		limit_chicken.clear();
	} while(prev_permutation(c.begin(),c.end())); 
	
}

void Solve() {
	Combination();
}

int main(void) {
	Input();
	Solve();
	cout << answer;
	return 0;	
}

