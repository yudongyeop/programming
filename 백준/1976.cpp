#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;

bool Edge[201][201];
vector<int> Plan;
bool Visit[201];
bool Possible[201][201];

void Input() {
	cin >> N >> M;
	
	int a;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cin >> a;
			if (i == j) {
				Edge[i][j] = true;
				Possible[i][j] = true;
			}
			else Edge[i][j] = a;
		}
	}
	
	for (int i=0; i<M; i++) {
		cin >> a;
		Plan.push_back(a);
	}	
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	Visit[start] = true;
	//cout << "start : " << start << endl;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		for (int i=1; i<=N; i++) {
			if (Edge[v][i] == true && Visit[i] == false) {
				Visit[i] = true;
				q.push(i);
				//cout << " i : " << i << endl;
				Possible[start][i] = true;
			}
		}
	}
	memset(Visit,0,sizeof(Visit));
}

void Solve() {
	for (int i=1; i<=N; i++) {
		BFS(i);
	}
	
	for (int i=0; i<Plan.size()-1; i++) {
		if(Possible[Plan[i]][Plan[i+1]] == false) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
	return;
}

int main(void) {
	Input();
	Solve();
	return 0;
}

