#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> b;
vector<int> answer;
vector<int> num;
int T,A,B;

int binary_search(int n) {
	int low = 0;
	int high = a.size()-1;
	while (low <= high) {
		int mid = (low + high)/2;
		int mid_v = a[mid];
		if (mid_v > n) high = mid-1;
		if (mid_v <= n) low = mid+1;
	}
	
	return a.size()-low;
}

int main(void) {
	
	cin >> T;
	
	for (int i=0; i<T; i++) {
		cin >> A >> B;
		int tmp;
	
		for (int i=0; i<A; i++) {
			cin >> tmp;
			a.push_back(tmp);
		}
		
		for (int i=0; i<B; i++) {
			cin >> tmp;
			b.push_back(tmp);
		}
		sort(a.begin(), a.end());
		for (int i=0; i<B; i++) {
			answer.push_back(binary_search(b[i]));
		}
		int sum = 0;
		for (int i=0; i<answer.size(); i++) {
			sum += answer[i];
		}
		num.push_back(sum);
		a.clear();
		b.clear();
		answer.clear();
	}
	for (int i=0; i<num.size(); i++) cout << num[i] << '\n'; 

	
	return 0;
}
