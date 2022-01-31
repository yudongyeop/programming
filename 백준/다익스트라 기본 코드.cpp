#include <iostream>
#include <vector>

using namespace std;

int V, E, Start = 0;

bool Visit[20001];
vector<vector<short>> Edge(20001,vector<>(20001,2000));

int Dst[20001];

void Input() {
	cin >> V >> E >> Start;
	
	int a, b, c;
	

	for (int i=0; i<E; i++) {
		cin >> a >> b >> c;
		Edge[a][b] = c;
	}
}

int ShortestV() {
	int MinCost = 2000;
	int MinIndex = -1;
	
	for (int i=1; i<=V; i++) {
		if (Visit[i]) continue;
		 
		if (Dst[i] < MinCost) {
			MinCost = Dst[i];
			MinIndex= i;
		}
	}
	//cout << MinIndex << endl;
	return MinIndex;
}

void Update(int NewNode) {
	for (int i=1; i<=V; i++) {
		if (Visit[i]) continue;
		
		if (Dst[NewNode] + Edge[NewNode][i] < Dst[i]) {
			Dst[i] = Dst[NewNode] + Edge[NewNode][i];
		}
	}
}

void Solve() {
	Input();
	
	Visit[Start] = true;
	
	for (int i=1; i<=V; i++) {
		Dst[i] = Edge[Start][i];
	}
	
	Dst[Start] = 0;
	
	for (int i=0; i<V-1; i++) {
		int NewNode = ShortestV();
		if (NewNode == -1) break;
		Visit[NewNode] = true;
		
		Update(NewNode);
	}
	
	for (int i=1; i<=V; i++) {
		if (Dst[i] == 2000) cout << "INF" << '\n';
		else cout << Dst[i] << '\n';
	}

}

int main(void) {
	Solve();
	return 0;
}
