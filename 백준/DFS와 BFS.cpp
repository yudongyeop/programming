#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int V, vector<int>* graph, bool* visit) {
	if (visit[V] == false) {
		cout << V << " ";
		visit[V] = true;
		for (int i=0; i<graph[V].size(); i++) {
			dfs(graph[V][i], graph, visit);
		}
	}
}

int main(void) {
	int N, M, V;
	cin >> N >> M >> V;
	
	vector<int> graph[N+1];
	
	int x,y=0;
	
	for (int i=0; i<M; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i=1; i<N+1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	bool visit[N+1] = {0};
	bool visit2[N+1] = {0};
	
	dfs(V, graph, visit2);
	cout << endl;
	
	queue<int> bfs;
	bfs.push(V);
	
	while (!bfs.empty()) {
		int tmp = bfs.front();
		bfs.pop();
		if (visit[tmp] == false) {
			visit[tmp] = true;
			cout << tmp << " ";
			for (int i=0; i<graph[tmp].size(); i++) {
				bfs.push(graph[tmp][i]);
			}
		}
	}
	
	return 0;
}
	
	



