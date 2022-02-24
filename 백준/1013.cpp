#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
string e[2000];
string ans[2000];

int main(void) {
	cin >> N;
	string tmp;
	int max_size = 0;
	for (int i=0; i<N; i++) {
		cin >> tmp;
		e[i] = tmp;
	}
	
	
	for (int i=0; i<N; i++) {
		ans[i] = "YES";
	}
	for (int k=0; k<N; k++) {
		string s = e[k];
		int state = 1;
		if (s.size() == 1) {
			ans[k] = "NO";
			continue;
		}
		else if (s.size() == 2) {
			if (s != "01") {
				ans[k] = "NO";
				continue;
			}
		}
		
		for (int i=0; i<s.size(); i++) {
			char next = s[i];
			bool stop = false;
			//cout << state;
			switch(state) {
			
				case 1:
					if (next == '0') state = 3;
					
					else if (next == '1') state = 2;
					
					break;
				case 2:
					if (next == '0') state = 4;
					else {
						ans[k] = "NO";
						stop = true;
					}
					break;
				
				case 3:
					if (next == '1') state = 1;
					else {
						ans[k] = "NO";
						stop = true;
					}
					break;
				
				case 4:
					if (next == '0') state = 5;
					else {
						ans[k] = "NO";
						stop = true;
					}
					break;
				
				case 5:
					if (next == '0') state = 6;
					else state = 7;
					break;
				
				case 6:
					if (next == '1') state = 7;
					else state = 6;
					break;
				case 7:
					if (next == '1') state = 8;
					else state = 3;
					break;
				case 8: 
					if (next == '1') state = 8;
					else state = 9;
					break;
				case 9:
					if (next == '1') state = 1;
					else state = 5;
					break;
			}
			if(stop) break;
		}
		
		if (state == 3 || state == 2 || state == 4 || state == 5 || state == 9 || state == 6) ans[k] = "NO";
	}
	
	for (int i=0; i<N; i++) {
		cout << ans[i] << '\n';
	}
 	
	
	return 0;
	
}
