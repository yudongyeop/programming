#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N; 
vector<int> Crane;
int M;
vector<int> Box;
int day;

void Input() {
	cin >> N;
	int a;
	for (int i=0; i<N; i++) {
		cin >> a;
		Crane.push_back(a);
	}
	cin >> M;
	for (int i=0; i<M; i++) {
		cin >> a;
		Box.push_back(a);
	}
}

bool mycompare(int a, int b) {
	return a > b;
}

void Move() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<Box.size(); j++) {
			if (Crane[i] >= Box[j]) {
				Box.erase(Box.begin()+j);
				break;
			}
		}
	}
}
bool check() {
	for (int i=0; i<M; i++) {
		if (Box[i] != -1) return false;
	}
	return true;
}

void Solution() {
	sort(Crane.begin(), Crane.end(), mycompare);
	sort(Box.begin(), Box.end(), mycompare);
	
	if (Crane[0] < Box[0]) {
		cout << "-1";
		return;
	}
	
	while (Box.size() > 0) {
		Move();
		day++;
	}
	
	cout << day;
}
void Solve() {
	Input();
	Solution();
}

int main(void) {
	Solve();
	
	return 0;
}
