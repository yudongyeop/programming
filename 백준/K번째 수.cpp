#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(void) {
	ll N,k;
	cin >> N >> k;
	ll answer = 0;
	 
	for (ll i=1; i<=N; i++) {
		for (ll j = i; j<=N; j++) {
			ll tmp = i*j;
			if(i == j) answer ++;
			else answer += 2;
			
			if (answer == k || answer == k+1) {
				cout << tmp << endl;
				return 0;
			}		
		}
	}
	return 0;
}


