#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> t;

int V, E;

vector<t> graph;

int sum;
int link[10001];

bool mycompare(t a, t b) {
	return get<2>(a) < get<2>(b);
}

int getParent(int x) {
	if(link[x] == x) return x;
	return link[x] = getParent(link[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	if (a < b) link[b] = a;
	else link[a] = b;
}

int find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	if (a == b) return 1;
	else return 0;
}

void Input() {
	cin >> V >> E;
	int a,b,c;
	
	for (int i=0; i<E; i++) {
		cin >> a >> b >> c;
		graph.push_back(make_tuple(a,b,c));
	}
	
	for (int i=0; i<V; i++) {
		link[i] = i;
	}
}

void Kruskal() {
	sort(graph.begin(), graph.end(), mycompare);
	for (int i=0; i<E; i++) {
		if (!find(get<0>(graph[i])-1, get<1>(graph[i])-1)) {
			sum+= get<2>(graph[i]);
			unionParent(get<0>(graph[i])-1, get<1>(graph[i])-1);
		}
	}
}

void Solve() {
	Input();
	Kruskal();
	cout << sum;
}

int main() {
	Solve();
}
