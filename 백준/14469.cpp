#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> p;

int N;
vector<p> v;

bool MyCompare(pair<int,int> a, pair<int,int> b) {
	return a.first < b.first;	
}

void Input() {
	cin >> N;
	int a, b;
	for (int i=0; i<N; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
}

void Solve() {
	sort(v.begin(),v.end(),MyCompare);
	
	int t = 0;
	
	for (int i=0; i<v.size(); i++) {
		int Arrive = v[i].first;
		int Wait = v[i].second;
		
		if (t <= Arrive) {
			t = Arrive + Wait;
		}
		else t += Wait;
		
	}
	cout << t;
}


int main(void) {
	Input();
	Solve();
	return 0;
	
}
