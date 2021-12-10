#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll N, B, C;
vector<ll> A;

void Input() {
	cin >> N;
	
	ll a;
	for (ll i=0; i<N; i++) {
		cin >> a;
		A.push_back(a);
	}
	
	cin >> B >> C;
}

void Solve() {
	ll answer = 0;
	
	for (ll i=0; i<A.size(); i++) {
		ll student = A[i]-B;
		answer++;
		if (student < 0) continue; 
		
		
		if (student%C == 0) student /= C;
		else student = (student/C) + 1;
		
		answer+= student; 
			
	}
	cout << answer;
}
int main(void) {
	Input();
	Solve();
	
	return 0;
}
