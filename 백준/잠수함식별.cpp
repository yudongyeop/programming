#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;
	
	int s = 1;
	
	for (int i=0; i<str.size(); i++) {
		//cout << s << endl;
		if (s == 1) {
			if (str[i] == '1') s = 2;
			else s = 3;
		}
		else if (s == 2) {
			if (str[i] == '1') { 
				cout << "NOISE";
				return 0;
			}
			else s = 4;
		}
		else if (s == 4) {
			if (str[i] == '1') {
				cout << "NOISE";
				return 0;
			}
			else s = 5;
		}
		
		else if (s == 5) {
			if (str[i] == '1') s= 6;
			else s = 5;
		}
		
		else if (s == 6) {
			 if (str[i] == '1') s = 6;
			 else if (str[i] == '0' && str[i-2] == '1' && str[i+1] == '0' && i != str.size()-1) s = 5;
			 else if (str[i] == '0' && str[i+1] == '1' && i != str.size()-1) s = 7;
		}
		else if (s == 3) {
			if (str[i] == '0') {
				cout << "NOISE";
				return 0;
			}
			else s = 7;
		}
		else if (s == 7) s = 1;
	}
	
	cout << "SUBMARINE";
	return 0;
}
		
		
	

