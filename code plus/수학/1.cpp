#include <iostream>

using namespace std;

typedef long long ll;

int main(void) {

	int N;	
	while (scanf("%d", &N) != EOF) {
		int cnt = 1;
		int tmp = 1;
		
		while (1) {
			if (tmp%N == 0) {
				cout << cnt << '\n';
				break;
			}
			else {
				tmp = (tmp*10)%N + 1;
				cnt++;
			}
		}	
		
	}
	return 0;
}
