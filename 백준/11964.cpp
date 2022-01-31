#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<double,bool> p;

int T, A, B;
int Max;
bool Check[5000001][2];

void BFS() {
	queue<p> q;
	q.push(make_pair(0,0));
	Check[0][0] = true;
	
	while (!q.empty()) {
		int cur_T = q.front().first;
		bool water = q.front().second;
		q.pop();
		if (cur_T >= Max) Max = cur_T;
		
		if (water == false && Check[cur_T/2][!water] == false) {
			q.push(make_pair(cur_T/2,!water));
			Check[cur_T/2][!water] = true;	
		}
		if (cur_T + A <= T && Check[cur_T+A][water] == false) {
			q.push(make_pair(cur_T+A,water));
			Check[cur_T+A][water] = true;
		} 
		if (cur_T + B <= T && Check[cur_T+B][water] == false) {
			q.push(make_pair(cur_T+B,water));
			Check[cur_T+B][water] = true;
		}
	}		
}

int main(void) {
	cin >> T >> A >> B;
	
	BFS();
	
	cout << int(Max);
	
}
