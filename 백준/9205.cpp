#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

typedef pair<int,int> p;

int T, n;

vector<p> home;
vector<p> store;
vector<p> festival;
vector<string> ans;

bool visit[100];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int Distance(int x1, int y1, int x2, int y2) {
	return (abs(x1-x2) + abs(y1-y2));
}


void Input() {
	cin >> n;
	
	int a, b;
	cin >> a >> b;
	home.push_back(make_pair(a,b));
	
	for (int i=0; i<n; i++) {
		cin >> a >> b;
		store.push_back(make_pair(a,b));
	}
	
	cin >> a >> b;
	festival.push_back(make_pair(a,b));	
}

void BFS() {
	queue<p> q;
	q.push(make_pair(home[0].first, home[0].second));
	
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		
		if (Distance(x,y,festival[0].first, festival[0].second) <= 1000) {
			ans.push_back("happy");
			return;
		}
		
		for (int i=0; i<n; i++) {
			int nx = store[i].first;
			int ny = store[i].second;
			
			if (Distance(x,y,nx,ny) <= 1000 && !visit[i]) {
				visit[i] = true;
				q.push(make_pair(nx,ny));
			}
		}
	}
	ans.push_back("sad");
}

void Solution() {
	BFS();
}

void Solve() {
	cin >> T;
	for (int i=0; i<T; i++) {
		Input();
		Solution();
		home.clear();
		store.clear();
		festival.clear(); 
		memset(visit,0,sizeof(visit));
	}
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}

int main(void) {
	Solve();
	return 0;
}
