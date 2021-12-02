#include <iostream>
#include <algorithm>

//combination solution

using namespace std;

int ability[20][20];
int N;
vector<int> person;
vector<int> c;

vector<int> team1;
vector<int> team2;
 
int main(void) {
	cin >> N;
	int min;
	
	int cnt = 0;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> ability[i][j];
		}
	}
	for (int i=0; i<N; i++) person.push_back(i);
	for (int i=0; i<N; i++) {
		if(i < N/2) c.push_back(1);
		else c.push_back(0);
	}
	
	do {
		for (int i=0; i<person.size(); i++) {
			if (c[i] == 1) team1.push_back(person[i]);
			else team2.push_back(person[i]);
		}
		int sum1 = 0;
		int sum2 = 0;
		
		for (int z=0; z<team1.size()-1; z++) {
			for (int k=z+1; k<team1.size(); k++) {
				sum1+=ability[team1[z]][team1[k]];
				sum1+=ability[team1[k]][team1[z]];
			}
		}
		for (int a=0; a<team2.size()-1; a++) {
			for (int b=a+1; b<team2.size(); b++) {
				sum2+=ability[team2[a]][team2[b]];
				sum2+=ability[team2[b]][team2[a]];
			}
		}
		if(cnt == 0) {
			if (sum1 >= sum2) min = sum1 - sum2;
			else min = sum2 - sum1;	
		}
		else {
			if (sum1 >= sum2 && min >= (sum1 - sum2) ) min = sum1 - sum2;
			else if (sum1 < sum2 && min >= (sum2-sum1)) min = sum2 - sum1;
		}
		cnt ++;
		team1.clear();
		team2.clear();
	} while (prev_permutation(c.begin(), c.end()));
	
	cout << min;
	return 0;
}
