//완전 탐색
 
#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

typedef tuple<int,int,int> t;

int N,M;
int office[8][8];
int tmp_office[8][8];
int Min = 86;

vector<t> cctv;
int cctv_num;
vector<vector<int>> directions; 
vector<int> d = {0,1,2,3};

void Input() {
	cin >> N >> M;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> office[i][j];
		}
	} // Input office
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (office[i][j] != 0) {
				cctv.push_back(make_tuple(i,j,office[i][j]));
				cctv_num++;
			}
		}
	} // Input cctv
	
}

void east(int x, int y) {
	for (int i=y; i<M; i++) {
		if (tmp_office[x][i]==6) break;
		else if (tmp_office[x][i]==0) tmp_office[x][i] = 7;
	}
}

void west(int x, int y) {
	for (int i=y; i>=0; i--) {
		if (tmp_office[x][i]==6) break;
		else if (tmp_office[x][i]==0) tmp_office[x][i] = 7;
	}
}

void south(int x, int y) {
	for (int i=x; i<N; i++) {
		if (tmp_office[i][y]==6) break;
		else if (tmp_office[i][y]== 0) tmp_office[i][y] = 7;
	}
}

void north(int x, int y) {
	for (int i=x; i>=0; i--) {
		if (tmp_office[i][y]== 6) break;
		else if (tmp_office[i][y]== 0) tmp_office[i][y] = 7;
	}
}

void FindDirections(vector<int> v, int depth) {
	if (depth == cctv_num) directions.push_back(v);
	else {
		for (int i=0; i<d.size(); i++) {
			v.push_back(d[i]);
			FindDirections(v,depth+1);
		}
	}
	
}


void Solve(vector<int> direction) {
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			tmp_office[i][j] = office[i][j];
		}
	}
	
	for (int i=0; i<cctv_num; i++) {
		int x = get<0>(cctv[i]);
		int y = get<1>(cctv[i]);
		int z = get<2>(cctv[i]); // cctv 종류
		int di = direction[i]; 
		
		if (z == 1) {
			if (di == 0) east(x,y);
			if (di == 1) south(x,y);
			if (di == 2) west(x,y);
			if (di == 3) north(x,y);
		}
		
		if (z == 2) {
			if (di == 0 || di == 2) {
				east(x,y);
				west(x,y);
			}
			if (di == 1 || di == 3) {
				south(x,y);
				north(x,y);
			}
		}
		
		if (z == 3) {
			if (di == 0) {
				north(x,y);
				east(x,y);
			}
			if (di == 1) {
				east(x,y);
				south(x,y);
			}
			if (di == 2) {
				west(x,y);
				south(x,y);
			}
			if (di == 3) {
				north(x,y);
				west(x,y);
			}
		}
		
		if (z == 4) {
			if (di == 0) {
				north(x,y);
				east(x,y);
				west(x,y);
			}
			if (di == 1) {
				north(x,y);
				east(x,y);
				west(x,y);
			}
			if (di == 2) {
				east(x,y);
				west(x,y);
				south(x,y);
			}
			if (di == 3) {
				north(x,y);
				south(x,y);
				west(x,y);
			}
		}
		
		if (z == 5) {
			east(x,y);
			west(x,y);
			north(x,y);
			south(x,y);
		}
	}
	int answer = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (tmp_office[i][j] == 0) answer++; 
		}
	}
	if (Min >= answer) Min = answer;
	memset(tmp_office,0,sizeof(tmp_office)); 
}

int main(void) {
	
	Input();
	vector<int> v(cctv_num);
	FindDirections(v,0);
	
	for (int i=0; i<directions.size(); i++) {
		Solve(directions[i]);
	}
	
	for (int i=0; i<directions.size(); i++) {
		for (int j=0; j<cctv_num; j++) {
			cout << directions[i][j] << " "; 
		}
		cout << endl;
	}
	cout << Min;
	
	return 0;
}

