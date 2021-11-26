#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll BinarySearch(vector<ll>& v, ll tmp) {
	ll low = 0;
	ll high = v.size()-1;
	while (low != high) {
		
		ll mid = (low+high)/2;
		ll mv = v[mid];
		
		
		if (tmp > mv) low = mid + 1;
		else high = mid;
	}
	
	return high;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll N,K;
	cin >> N;
	cin >> K;
	
	vector<ll> v;
	ll tmp;
	
	for (ll i=1; i<=N; i++) {
		for (ll j=1; j<=N; j++) {	
			tmp = i * j;
			if (v.empty() || v.back() < tmp) v.push_back(tmp);
			else {
				ll low_idx = BinarySearch(v, tmp); 
				v.insert(v.begin()+low_idx, tmp);
			}
		}		
	}
	cout << v[K];
	return 0;
}
