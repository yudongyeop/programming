#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int,int> p;

int N,M;//¼öºó, µ¿»ý 

bool visit[100001];
int walk[] = {1,-1};

int bfs() {
	int cur = N;
	queue<p> q;
	int answer = 0;
	q.push(make_pair(cur,0));
	
	while (1) {
		int x = q.front().first;
		int seq = q.front().second;
		q.pop();
		//cout << "x " << x << "seq : " << seq << endl;
		if(x == M) {
			answer = seq; 
			break;
		}
		visit[x] = true;
			
		for (int i=0; i<2; i++) {
			int nx = x+walk[i];
			
			if (visit[nx]==false) {
				if (nx >= 0 && nx <= 100000) q.push(make_pair(nx,seq+1));
			}
		}
			
		if (visit[2*x]==false) {
			if (2*x >= 0 && 2*x <= 100000) q.push(make_pair(2*x,seq+1));
		}
		
	}
	return answer;
}

int main(void) {
	cin >> N >> M;
	int answer = bfs();
	cout << answer;
	return 0;
}
