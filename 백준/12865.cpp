#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> p;

int N, K;
vector<p> Item;
int P[101][100001];

void Input() {
	cin >> N >> K;
	Item.push_back(make_pair(0,0));
	int a, b;
	for (int i=0; i<N; i++) {
		cin >> a >> b;
		Item.push_back(make_pair(a,b));
	}
	
}

void Solve() {
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=K; j++) {
			if (Item[i].first <= j) {
				P[i][j] = max(P[i-1][j], P[i-1][j-Item[i].first]+Item[i].second);
			}
			else P[i][j] = P[i-1][j];	
		}
	}
	cout << P[N][K] << endl;
}	


int main(void) {
	Input();
	Solve();
	return 0;
	
}
