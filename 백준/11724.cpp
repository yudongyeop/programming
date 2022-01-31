#include <iostream>
#include <queue>

using namespace std;

int N, M, Com;
bool Edge[1001][1001];
bool Visit[1001];


void Input() {
	cin >> N >> M;
	int a, b;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		Edge[a][b] = true;
		Edge[b][a] = true;
	}
}
int Check() {
	for (int i=1; i<=N; i++) {
		if (!Visit[i]) return i; 
	}
	return -1;
}

void BFS(int v) {
	queue<int> q;
	q.push(v);
	Visit[v] = true;
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		for (int i=1; i<=N; i++) {
			if (Edge[v][i] && !Visit[i]) {
				Visit[i] = true;
				q.push(i);
			} 
		}
	}	
}
void Solve() {
	Input();
	while (true) {
		int v = Check();
		if (v == -1) break;
		BFS(v);
		Com++;
	}
	
	cout << Com;
}

int main(void) {
	Solve();
	return 0;
}
