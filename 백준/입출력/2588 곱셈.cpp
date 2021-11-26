#include <iostream>

using namespace std;

int main(void) {
	int a,b;
	cin >> a >> b;
	
	int c,d,e;
	
	c = a*(b%10);
	d = (b%100);
	d = d/10;
	d = a*d;
	
	e = a* (b/100);
	
	cout << c << '\n' << d << '\n' << e << '\n' << c+d*10+e*100; 
	
} 
