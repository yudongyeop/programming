#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string format;
	cin >> format;
	
	int num = 10;
	int letter = 26;
	
	int ans = 1;
	char prev = 'a';
	
	for (int i=0; i<format.size(); i++) {
		if (format[i] == 'c' && prev != format[i]){
			ans *= letter;
			prev = 'c';
		}
		else if (format[i] == 'c' && prev == format[i]){
			ans *= letter-1;
			prev = 'c';	
		}
		
		else if (format[i] == 'd' && prev != format[i]) {
			ans *= num;
			prev = 'd';
		}
		
		else if (format[i] == 'd' && prev == format[i]){
			ans *= num-1;
			prev = 'd';	
		}
	} 
	
	cout << ans;
	
	return 0;
	
}
