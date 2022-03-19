#include <iostream>
#include <climits>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> t;

int N, M;

int Max = 0;

vector<t> limit;
vector<t> test;

bool overlap(t a, t b) {
	if (get<1>(a) <= get<0>(b) || get<0>(a) >= get<1>(b)) return false;
	else return true;
}

int main(void) {
	cin >> N >> M;
	
	int a, b;
	int start = 0;
	
	for (int i=0; i<N; i++) {
		cin >> a >> b;
		limit.push_back(make_tuple(start,start+a,b));
		start += a;	
	}
	start = 0;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		test.push_back(make_tuple(start,start+a,b));
		start += a;	
	}
	
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			if (overlap(limit[j], test[i])) {
				cout << " i, j : " << i << " " << j << endl;
 				if (Max < get<2>(test[i]) - get<2>(limit[j])) Max = get<2>(test[i]) - get<2>(limit[j]);
			}
		}
	}
	
	cout << Max;
	
	return 0;
}
