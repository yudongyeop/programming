//bipartite graph, BFS solution
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
 
typedef long long ll;
 
ll T, V, E;
vector<ll> graph[20001];
ll vcolor[20001]; // 0 -> none, 1 -> red, 2 -> blue
vector<bool> answer;

bool bfs(int n) {
	queue<ll> q;
	q.push(n);
	vcolor[n] = 1; // start node's color is red(1)
	while(!q.empty()) {
		ll v = q.front();
		q.pop();
		for (ll i=0; i<graph[v].size(); i++) {
			ll nv = graph[v][i];
			
			if (vcolor[nv] == 0 && vcolor[v] == 1) {
				vcolor[nv] = 2;
				q.push(nv);
			}
			else if (vcolor[nv] == 0 && vcolor[v] == 2) {
				vcolor[nv] = 1;
				q.push(nv);
			}
			else if (vcolor[nv] != vcolor[v]) continue;
			else if (vcolor[nv] == vcolor[v]) {
				return 0;
			}
		}
	} 
	return 1;
}

int main(void) {
	cin >> T;
	
	ll tmp1, tmp2;
	
	for (ll i=0; i<T; i++) {
		cin >> V;
		cin >> E;
		
		for (ll j=0; j<E; j++) {
			cin >> tmp1 >> tmp2;
			graph[tmp1].push_back(tmp2);
			graph[tmp2].push_back(tmp1);
		}
		
		int result = 0;
		for (ll z=1; z<=V; z++) {
			if(vcolor[z] == 0) {
				result = bfs(z);
				if (!result) break;
			}
		}
		
		answer.push_back(result);
		
		for (ll k=1; k<=V; k++) {
			graph[k].clear();
		}
		memset(vcolor,0,sizeof(vcolor));
	}
	for (ll i=0; i<answer.size(); i++) {
		if (answer[i] == true) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;	
}
