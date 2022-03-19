#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	int M, N, K;	
	cin >> M >> N >> K;
	
	string hidden = "";
	string user = "";
	
	int a;
	
	for (int i=0; i<M; i++) {
		cin >> a;
		hidden+= to_string(a);
	}
	for (int i=0; i<N; i++) {
		cin >> a;
		user+= to_string(a);
	}
	
	if (user.find(hidden) != string::npos) cout << "secret";
	else cout << "normal";
	
	return 0;
}
