// 모든 정점에서 모든 정점까지의 최단경로 출력 -> 플로이드 와샬 알고리즘 
#include <iostream>
#define INF 10000000
 
using namespace std;

int n, m;
int bus[101][101];

void Input() {
	cin >> n >> m;
	
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			bus[i][j] = 10000000;
		}
	}
	int a,b,c;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		bus[a][b] = min(bus[a][b], c); // 방향 그래프 
	}
	
	
}

void Solution() {
	for (int b=1; b<=n; b++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				bus[i][j] = min(bus[i][j], bus[i][b] + bus[b][j]);
			}
		}
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i==j) bus[i][j] = 0;
			if (bus[i][j] == 10000000) bus[i][j] = 0;
		}
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (j==n) cout << bus[i][j] << '\n';
			else cout << bus[i][j] << " ";
		}
	}
}
 
void Solve() {
	Input();
	Solution();
}
int main(void) {
	Solve();	
}
