#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visit[9];

void DFS(vector<int>& result, int cnt) {
	if (cnt == M) {
		for (int i=0; i<M; i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	else {
		for (int i=1; i<=N; i++) {
			if (!visit[i]) {
				visit[i] = true;
				result[cnt] = i;
				DFS(result, cnt+1);
				visit[i] = false;
			}
		}	
	}	
}

int main(void) {
	cin >> N >> M;
	vector<int> result(M,0);
	
	DFS(result,0);
	return 0;
}
