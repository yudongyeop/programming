#include <iostream>
#include <vector>

//여러 값들이 존재 -> 특정 기준을 정해서 최대값이나 최솟값을 구해야 하는 경우 -> 이분탐색을 생각해본다. 
using namespace std;

int N, M;
vector<int> Budget;
int Max;

void Input() {
	cin >> N;
	int a;
	for (int i=0; i<N; i++) {
		cin >> a;
		if (a > Max) Max = a;
		Budget.push_back(a);
	}
	cin >> M;
}

int BinarySearch() {
	int low = 0;
	int high = Max;
	int result = 0;
	while (low <= high) {
		int mid = (low+high)/2;
		long long sum = 0;
		for (int i=0; i<N; i++) {
			if (Budget[i] >= mid) {
				sum += mid;
			}
			else {
				sum+=Budget[i];
			}
		}
		
		if (sum > M) {
			high = mid-1;
			
		}
		else {
			result = mid;
			low = mid+1;
		}
	}
	
	return result;
}

void Solution() {
	int answer = BinarySearch();
	cout << answer;
}

void Solve() {
	Input();
	Solution();
}

int main(void) {
	Solve();
	return 0;
}
