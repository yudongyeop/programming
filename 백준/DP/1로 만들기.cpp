#include <iostream>

using namespace std;

int N;
int arr[1000001];

int main(void) {
	cin >> N;
	int answer = 0;
	
	arr[2] = 1;
	arr[3] = 1;
	
	for (int i=4; i<=N; i++) {
		if (i%2 == 0 && i%3 == 0) {
			//Â¦¼öÀÎ °æ¿ì
			arr[i] = min(arr[i/2]+1, arr[i/3]+1);
			arr[i] = min(arr[i], arr[i-1]+1);
		}
		else if (i%3 == 0 && i%2 != 0) {
			arr[i] = min(arr[i/3]+1,arr[i-1]+1);
		}
		else if (i%2 == 0 && i%3 != 0) {
			arr[i] = min(arr[i/2]+1,arr[i-1]+1);
		}
		else arr[i] = arr[i-1]+1; 
	}	
	answer = arr[N];
	cout << answer;
	
}
