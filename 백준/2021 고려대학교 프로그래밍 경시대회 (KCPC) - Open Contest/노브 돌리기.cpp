#include <iostream>

using namespace std;

int N;
int A[101];

int main(void) {
	cin >> N;
	cin >> A[0];
	
	for (int i=1; i<=N; i++) cin >> A[i];
	
	int sum = 0;
	
	for (int i=1; i<=N; i++) {
		int right = A[i] - A[i-1]; //90
		int left = A[i-1] - A[i]; // -90
		
		if (right < 0) right+=360;
		
		if (left < 0) left+=360;
		
		//cout << "left : " << left << "right : " << right << endl; 
		if (right <= left) sum+= right;
		else sum+= left; 
	}
	
	cout << sum;
	
	return 0;
}
