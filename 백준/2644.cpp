#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> p;

int n, m;

int start, End;

bool relation[101][101];
bool visit[101];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void BFS() {
	queue<p> q;
	q.push(make_pair(start,0)); 
	visit[start] = true;
	
	while (!q.empty()) {
		int v = q.front().first;
		int r = q.front().second;
		q.pop();
		if (v == End) {
			cout << r;
			return;
		}
		
		for (int i=1; i<=n; i++) {
			if ((relation[v][i] || relation[i][v]) && !visit[i]) {
				visit[i] = true;
				q.push(make_pair(i,r+1));
			}
		}
	}
	cout << "-1";
}

void Input() {
	cin >> n;
	cin >> start >> End;
	cin >> m;
	
	int a, b;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		relation[a][b] = true;
		relation[b][a] = true;
	}
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
