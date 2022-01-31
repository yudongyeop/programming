#include <iostream>

using namespace std;

int N;
int arr[5001];

int main(void) {
	cin >> N;
	int answer = 0;
	
	arr[3] = 1;
	arr[5] = 1;
	
	for (int i=6; i<=N; i++) {
		if (arr[i-3] != 0 && arr[i-5] == 0) arr[i] = arr[i-3]+1;
		else if (arr[i-3] == 0 && arr[i-5] != 0) arr[i] = arr[i-5]+1;
		else if (arr[i-3] != 0 && arr[i-5] != 0) arr[i] = min(arr[i-3]+1, arr[i-5]+1);
		else continue; 
	}
	
	
	if (arr[N] == 0) answer = -1;
	else answer = arr[N];
	cout << answer;
	
}
