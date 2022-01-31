#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int N,K;

int Check(int n) {
	bitset<32> bs(n);
	string str = bs.to_string();
	int num = 0;
	
	for (int i=0; i<str.size(); i++) {
		if (str[i] == '1') num++;
	}
	
	return num;
}

int main(void) {
	cin >> N >> K;
	
	int answer = 0;
	
	while (Check(N) > K) {
		N+=1;
		answer++;
	}
	cout << answer;
	
}
