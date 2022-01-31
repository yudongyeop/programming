#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> p;

int Switch, Student;

bool State[101];

vector<p> StudentList;

int main(void) {
	
	cin >> Switch;
	
	for (int i=1; i<=Switch; i++) cin >> State[i];	
	
	cin >> Student;
	
	int a, b;
	
	for (int i=0; i<Student; i++) {
		cin >> a >> b;
		StudentList.push_back(make_pair(a,b));
	}
	
	for (int i=0; i<Student; i++) {
		int gender = StudentList[i].first;
		int num = StudentList[i].second;
		
		//남학생 
		int b = 2;
		int tmp = num;
		
		if (gender == 1) {
			while (num <= Switch) {
				State[num] = !State[num];
				num = tmp * b;
				b++;
			} 
		}
		//여학생 
		if (gender == 2) {
			int k = 1;
			while(1) {
				if (num-k >= 1 && num+k <= Switch && State[num-k] == State[num+k]) k++;
				else break; 
			}
			k--;
			for (int j = num-k; j<= num+k; j++) State[j] = !State[j]; 
		}
	}
	
	for (int i=1; i<=Switch; i++) {
		if(i % 20 != 0) cout << State[i] << " ";
		else cout << State[i] << '\n';
	}
	
	return 0;
	
}
