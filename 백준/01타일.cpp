#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main(void) {
	ll N;
	cin >> N;
	
	vector<ll> v;
	v.push_back(1);
	v.push_back(2);
	
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	
	if (N == 2) {
		cout << 2 << endl;
		return 0;
	}
	ll tmp = 0;
	
	for (ll i=2; i<N; i++) {
		
		tmp = (v[i-2] + v[i-1])%15746;
		v.push_back(tmp);
	}
	
	cout << v[N-1]%15746 << endl;
	return 0;
}
