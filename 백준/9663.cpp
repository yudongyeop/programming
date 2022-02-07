#include <iostream>
#include <vector>

using namespace std;

int N;
int Map[15][15];
int Ans;

vector<int> Q(15,0);

bool Possible(int row, int idx) {
	if (row == 0) return true;
	int cnt = 1;
	for (int i=row-1; i>=0; i--) {
		if (Q[i] == idx-cnt || Q[i] == idx+cnt || Q[i] == idx) return false;
		cnt++;
	}
	return true;
}

void NQueen(int row) {
	if (row == N) {
		Ans++;
		return;
	}
	
	for (int i=0; i<N; i++) {
		if (Possible(row, i)) {
			Q[row] = i;
			NQueen(row+1);
		}
	}	
}

int main(void) {
	cin >> N;
	NQueen(0);
	cout << Ans;
	return 0;
}
