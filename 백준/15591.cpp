#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> p;

int N;
int Q;
vector<int> Answer;
vector<int> Graph[5001];
int USARDO[5001][5001];
int Visit[5001];
vector<p> Q_list;


void Input() {
	cin >> N >> Q;

	int a, b, c;
	for (int i=0; i<N-1; i++) {
		cin >> a >> b >> c;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
		USARDO[a][b] = c;
		USARDO[b][a] = c;
	}
	
	for (int i=0; i<Q; i++) {
		cin >> a >> b;
		Q_list.push_back(make_pair(a,b));
	}
}

int BFS(int K, int V) {
	queue<p> q;
	q.push(make_pair(V,0));
	Visit[V] = true;
	int cnt = 0;
	
	while(!q.empty()) {
		int v = q.front().first;
		int usardo = q.front().second;
		q.pop();
		if (usardo >= K) cnt++;
		
		for (int i=0; i<Graph[v].size(); i++) {
			int nv = Graph[v][i];
			
			if (Visit[nv] == false) {
				Visit[nv] = true;
				if (usardo == 0 || usardo >= USARDO[v][nv]) q.push(make_pair(nv,USARDO[v][nv]));
				else q.push(make_pair(nv,usardo));	
			}
		}
	}
	memset(Visit,0,sizeof(Visit));
	return cnt;
}

void Solution() { 
	
	for (int i=0; i<Q; i++) {
		int K = Q_list[i].first;
		int V = Q_list[i].second;
		
		Answer.push_back(BFS(K,V));
	}
	
	for (int i=0; i<Answer.size(); i++) {
		cout << Answer[i] << '\n';
	}
	
}

int main(void) {
	Input();
	Solution();
	return 0;
} 
