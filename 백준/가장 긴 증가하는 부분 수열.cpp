#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int>& v, int tmp) {
	int low = 0;
	int high = v.size()-1;
	while (low != high) {
		
		int mid = (low+high)/2;
		int mv = v[mid];
		
		
		if (tmp > mv) low = mid + 1;
		else high = mid;
	}
	
	return high;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> v;
	int tmp;
	
	for (int i=0; i<N; i++) {
		cin >> tmp;	
		if (v.empty() || v.back() < tmp) v.push_back(tmp);
		else {
			int low_idx = BinarySearch(v, tmp);
			v[low_idx] = tmp;
		}		
	}
	
	cout << v.size();
	return 0;
}
