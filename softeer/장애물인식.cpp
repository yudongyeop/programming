#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> p;

int N;
int map[25][25];
bool visit[25][25];
vector<int> answer;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


void Input() {
	
	cin >> N;
	string tmp;
	for (int i=0; i<N; i++) {
		cin >> tmp;
		for (int j=0; j<N; j++) {
			map[i][j] = tmp[j]-'0';
		}
	}
}

int BFS(int sx, int sy) {
	queue<p> q;
	q.push(make_pair(sx,sy));
	visit[sx][sy] = true;
	int result = 0;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		result++;
		cout << " result : " << result << endl;
		cout << " x : " << x << " y : " << y << endl;	
		q.pop();

		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
	
			if (x < 0 || x >= N || y < 0 || y >= N) continue;

			if (!visit[nx][ny] && map[nx][ny] == 1) {
				visit[nx][ny] = true;
				q.push(make_pair(nx,ny));
				
			}
		}
	}
	
	return result;
}

void Solution() {
	int cnt = 0;

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (!visit[i][j] && map[i][j] == 1) {
				cnt++;
				answer.push_back(BFS(i,j));
			}
		}
	}

	sort(answer.begin(), answer.end());
	
	cout << cnt << '\n';
	
	for (int i=0; i<answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}

void Solve() {
	Input();
	Solution();
}

int main(void)
{
	Solve();
	return 0;
}
