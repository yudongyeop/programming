#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(void) {
	ll N,M,tmp = 0;
	cin >> N;
	cin >> M;
	vector<ll> v;
	
	for (ll i=0; i<N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());
	
	ll low = 1;
	ll high = v[v.size()-1];
	while (low <= high) {
		ll mid = (low+high)/2;
		ll sum = 0;
		for (int i=0; i<v.size(); i++) sum += v[i]/mid;
		
		if (sum >= M) {
			low = mid+1;
		}
		else {
			high = mid-1;
		}
	}
	cout << high << '\n';
	
	return 0;
}
