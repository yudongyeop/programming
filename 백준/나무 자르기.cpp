#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef long long ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N,M,tmp;
	vector<ll> v;
	cin >> N >> M;
	for (ll i=0; i<N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	
	ll low = 0;
	ll high = v[v.size()-1];
	
	while (low <= high) {
		ll mid = (low+high)/2;
		ll sum = 0;
		for (ll i=0; i<N; i++) {
			ll leng = v[i] - mid;
			if (leng<0) leng=0;
			sum+= leng;
		}
		if (sum >= M) low = mid+1;
		else high = mid-1;
	}
	cout << high;
	return 0;
}
