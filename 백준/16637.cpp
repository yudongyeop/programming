#include <iostream>
#include <string>
#include <climits>

using namespace std;

int N;
string E;
int Ans = INT_MIN;

void Input() {
	cin >> N;
	cin >> E;
}

int Cal(int a, int b, char op) {
	if (op == '*') return a*b;
	else if (op == '+') return a+b;
	else if (op == '-') return a-b;
}


void DFS(int i, int sum) {
	
	//End
	if (i > N-1) {
		if (sum > Ans) Ans = sum;
		return;
	}
	
	char op;
	if (i == 0) op = '+';
	else op = E[i-1];

	//Bind
	if (i+2 < N) {
		int tmp = Cal(E[i]-'0', E[i+2]-'0', E[i+1]);
		
		DFS(i+4, Cal(sum, tmp, op));
	}
	
	// No Bind
	DFS(i+2, Cal(sum, E[i]-'0', op));
} 

void Solution() {
	DFS(0,0);
	cout << Ans;
}

void Solve() {
	Input();
	Solution();
	
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	Solve();
	return 0;
}
