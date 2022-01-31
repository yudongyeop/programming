#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

typedef pair<ll,ll> p;

ll N, K, R;
vector<p> cow;

bool road[10000][10000];
bool visit[100][100];
bool connect[101][101];

ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};

ll Map[100][100];

void Input() {
	cin >> N >> K >> R;
	
	for (ll i=0; i<R; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		
		ll x = (a-1)*N + (b-1);
		ll y = (c-1)*N + (d-1);
		
		road[x][y] = true;
		road[y][x] = true;
	}
	
	for (ll i=0; i<K; i++) {
		ll x,y;
		cin >> x >> y;
		cow.push_back(make_pair(x-1,y-1));
		Map[x-1][y-1] = i+1;
	}
		
}
	


void bfs(ll x, ll y, ll num) {
	queue<p> q;
	q.push(make_pair(x,y));
	visit[x][y] = true;
	
	while(!q.empty()) {
		ll x = q.front().first;
		ll y = q.front().second;
		q.pop();
		
		ll x2 = x*N + y;
		
		for (ll i=0; i<4; i++) {
			ll nx = x+dx[i];
			ll ny = y+dy[i];
			ll y2 = nx*N + ny;
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || road[x2][y2] == true) continue;
			
			if(visit[nx][ny] == false) {
				if (Map[nx][ny] > num) connect[num][Map[nx][ny]]= true;
				visit[nx][ny] = true;
				q.push(make_pair(nx,ny));
			}
		}
	}
	
	memset(visit,0,sizeof(visit));	
}
void Solve() {
	for (ll i=0; i<cow.size(); i++) {
		bfs(cow[i].first, cow[i].second, i+1);
	}
	ll answer = 0;
	for (ll i=1; i<K; i++) {
		for (ll j=i+1; j<=K; j++) {
			if (connect[i][j] == false) answer++;
				//cout << "x : " << i << " y : " << j << " ? : " << connect[i][j] << endl;
		}		
	}
	
	cout << answer;
}

int main(void) {
	Input();
	Solve();
	return 0;
}
