#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

typedef pair<int,int> p;

int V, E, Start;

vector<p> Graph[20001];
int Dst[20001];

void Input() {
	cin >> V >> E >> Start;
	int a, b, c;
	
	for (int i=0; i<E; i++) {
		cin >> a >> b >> c;
		Graph[a].push_back(make_pair(b,c));
	}
	for (int i=1; i<=V; i++) {
		Dst[i] = INF;
	}	
}

void Dikstra() {
	priority_queue<p> pq;
	pq.push(make_pair(0, Start));
	Dst[Start] = 0;
	
	while (!pq.empty()) {
		int v = pq.top().second;
		int c = -pq.top().first;
		pq.pop();
		
		for (int i=0; i<Graph[v].size(); i++) {
			int nv = Graph[v][i].first;
			int nc = Graph[v][i].second;
			
			if (Dst[nv] > c + nc) {
				
				Dst[nv] = c + nc;
				pq.push(make_pair(-Dst[nv], nv));
				Dst[nv] = c + nc;
			}
		}
	}
}

void Solve() {
	Input();
	Dikstra();
	for (int i=1; i<=V; i++) {
		if (Dst[i] == INF) cout << "INF" << '\n';
		else cout << Dst[i] << '\n';
	}
}
int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

	Solve();	
} 
