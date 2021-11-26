#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void BinarySearch(vector<int>& a, vector<int>& b, vector<int>& answer) {
	for (int i=0; i<b.size(); i++) {
		int low = 0;
		int high = a.size()-1;
		bool flag = false;
		while (low<=high) {
			int mid = (low+high)/2;
			int mid_value = a[mid];
			if (mid_value == b[i]) {
				answer.push_back(1);
				flag = true;
				break;
			}
			else if (b[i] < mid_value) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		if (!flag) answer.push_back(0);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	vector<int> A;
	vector<int> B;
	vector<int> answer;
	cin >> n;
	for (int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	cin >> m;
	for (int i=0; i<m; i++) {
		int tmp;
		cin >> tmp;
		B.push_back(tmp);
	}
	sort(A.begin(), A.end());
	
	BinarySearch(A, B, answer);	
	
	for (int i=0; i<answer.size(); i++) {
		cout << answer[i] << '\n';
	}	
}
