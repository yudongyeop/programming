#include <iostream>
#include <vector>

using namespace std;

int n;
long double ans;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
double px[4];

bool map[30][30];

void Input() {
	cin >> n;
	for (int i=0; i<4; i++) {
		long double a;
		cin >> a;
		px[i] = a/100;
	}
}

double DFS(int m, int x, int y) {
	if (m == n) return 1;	
	
	
	map[x][y] = true;
	double Result = 0;
	
	for (int i=0; i<4; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if (map[nx][ny]) continue;
		Result = Result + px[i]*DFS(m+1, nx, ny);
	}
	
	map[x][y] = false;
	return Result;
}
 
void Solution() {
	map[14][14] = true;
	ans = DFS(0,14,14);
	cout.precision(10);
	cout << ans;
}

void Solve() {
	Input();
	Solution();
}

int main(void) {
	Solve();
	return 0;
}
