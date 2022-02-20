#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int F, S, G, U, D;

bool Visit[1000001];

void Input() {
	cin >> F >> S >> G >> U >> D;
}

void BFS() {
	queue<p> q;
	q.push(make_pair(S, 0));
	Visit[S] = true;
	
	while (!q.empty()) {
		int cur = q.front().first;
		int n = q.front().second;
		q.pop();
		
		if (cur == G) {
			cout << n;
			return;
		}
		
		if (cur + U <= F && !Visit[cur+U]) {
			q.push(make_pair(cur+U,n+1));
			Visit[cur+U] = true;
		}
		
		if (cur - D >= 1 && !Visit[cur-D]) {
			q.push(make_pair(cur-D,n+1));
			Visit[cur-D] = true;	
		}
	}
	cout << "use the stairs";
}

void Solution() {
	BFS();
}

void Solve() {
	Input();
	Solution();
}
int main(void) {
	Solve();
	return 0;
}
