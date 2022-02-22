#include <iostream>
#include <vector>

using namespace std;

typedef pair<double,double> p;

int N;
int Ans;

vector<p> building;

bool possible[50][50];

void Input() {
	cin >> N;
	int a;
	for (int i=0; i<N; i++) {
		cin >> a;
		building.push_back(make_pair(i+1,a)); 
	}
}

bool Cansee(int i, int j) {
	double x1 =building[i].first;
	double y1 =building[i].second;
	double x2 =building[j].first;
	double y2 =building[j].second;
	
	double a = (y2-y1) / (x2-x1);
	double b = y1 - (a * x1);
	for (int k = i+1; k<j; k++) {
		double nx = building[k].first;
		double ny = building[k].second;
		
		double limit = (a * nx) + b;
		
		if (ny >= limit) return false;
	}
	
	return true;
}

void Solution() {
	
	for (int i=0; i<building.size()-1; i++) {
		for (int j=i+1; j<building.size(); j++) {
			if (Cansee(i,j)) {
				possible[i][j] = true;
				possible[j][i] = true;
			}
		}
	}
	
	for (int i=0; i<N; i++) {
		int result = 0;
		for (int j=0; j<N; j++) {
			if (possible[i][j]) {
				//cout << "i : " << i << " j : " << j << endl;
				result++;
			}
		}
		
		if (Ans < result) Ans = result;
	}
	
	cout << Ans;
}

void Solve() {
	Input();
	Solution();
}
int main(void) {
	Solve();
	return 0;
}
