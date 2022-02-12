#include <iostream>

using namespace std;

int N, r, c;
int Ans;

void Input() {
	cin >> N >> r >> c;
	
}

void Recur(int x, int y, int size) {
	if (x == r && y == c) {
		cout << Ans;
		return;
	}
	
	if (r < x + size && r >= x && c < y+size && c >= y) {
		Recur(x, y, size/2);
		Recur(x, y+(size/2), size/2);
		Recur(x+(size/2), y, size/2);
		Recur(x+(size/2), y+(size/2), size/2);
	}
	
	else Ans+= size*size;
}
void Solution() {
	int size = (1 << N);
	Recur(0,0,size);
}
void Solve() {
	Input();
	Solution();
}
int main(void) {
	Solve();
	return 0;
}


