//DFS(backtracking, 완전탐색) 
 
#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

typedef tuple<int,int,int> t;

int N,M;

int Min = 86;
vector<vector<int>> v;

vector<t> cctv;
int cctv_num = 0; 

void Input() {
	cin >> N >> M;
	vector<int> tmpv;
	int tmp;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> tmp;
			tmpv.push_back(tmp);
		}
		v.push_back(tmpv);
		tmpv.clear();
	} // Input office
	
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (v[i][j] != 0 && v[i][j] != 6) {
				cctv.push_back(make_tuple(i,j,v[i][j]));
				cctv_num++;
			}
		}
	} // Input cctv	

}

void check(int x, int y, int z, vector<vector<int>>& tmp_office) {

	
	switch(z) {
		case 0: //90 east 0
			for (int i=y; i<M; i++) {
				if (tmp_office[x][i]==6) break;
				else if (tmp_office[x][i]==0) tmp_office[x][i] = 7;
			}
			break;
		
		case 1: //270	west 1
			for (int i=y; i>=0; i--) {
				if (tmp_office[x][i]==6) break;
				else if (tmp_office[x][i]==0) tmp_office[x][i] = 7;
			}
			break;
		
		case 2: //180 south 2
			for (int i=x; i<N; i++) {
				if (tmp_office[i][y]==6) break;
				else if (tmp_office[i][y]== 0) tmp_office[i][y] = 7;
			}
			break;
		
		case 3: //360 north 3
			for (int i=x; i>=0; i--) {
				if (tmp_office[i][y]== 6) break;
				else if (tmp_office[i][y]== 0) tmp_office[i][y] = 7;
			}
			break;
	}
}

void DFS(int depth, vector<vector<int>> prev) {
	vector<vector<int>> tmp_office(N,vector<int>(M,0));
	if (depth == cctv_num) {
		int answer = 0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (prev[i][j] == 0) {
					answer++;
					//cout << "i : " << i << " j : " << j << endl;	
				} 
			}
		}
		if (Min >= answer) Min = answer;		
	}
	else {
		int x = get<0>(cctv[depth]);
		int y = get<1>(cctv[depth]);
		int z = get<2>(cctv[depth]); // cctv 종류
		
		
		switch(z) 
		{
			case 1:
				for (int i=0; i<4; i++) {
					for (int i=0; i<N; i++) {
						for (int j=0; j<M; j++) {
							tmp_office[i][j] = prev[i][j];
						}
					}
					check(x,y,i,tmp_office);
					DFS(depth+1, tmp_office);
				}
				break;
			
			case 2:
				for (int i=0; i<2; i++) {
					for (int i=0; i<N; i++) {
						for (int j=0; j<M; j++) {
							tmp_office[i][j] = prev[i][j];
						}
					} // 0 1 2 3 
					check(x,y,i*2,tmp_office);
					check(x,y,i*2+1,tmp_office);
					DFS(depth+1, tmp_office);
				}
				break;
			
			case 3:
				for (int i=0; i<4; i++) {
					for (int i=0; i<N; i++) {
						for (int j=0; j<M; j++) {
							tmp_office[i][j] = prev[i][j];
						}
					} // 0,2, 0,3 1,2 1,3
					check(x,y,i/2,tmp_office);
					check(x,y,(i%2)+2,tmp_office);
					DFS(depth+1, tmp_office);
				}
				break;
			
			case 4:
				for (int i=0; i<4; i++) {
					for (int i=0; i<N; i++) {
						for (int j=0; j<M; j++) {
							tmp_office[i][j] = prev[i][j];
						}
					} 
					check(x,y,i/3,tmp_office);
					check(x,y,(i%2)+1,tmp_office);
					if (i == 2) check(x,y,2,tmp_office);
					else check(x,y,3,tmp_office);
					DFS(depth+1, tmp_office);
				}
				break;
			case 5:
				for (int i=0; i<4; i++) {
					for (int i=0; i<N; i++) {
						for (int j=0; j<M; j++) {
							tmp_office[i][j] = prev[i][j];
						}
					} 
					check(x,y,0,tmp_office);
					check(x,y,1,tmp_office);
					check(x,y,2,tmp_office);
					check(x,y,3,tmp_office);
					DFS(depth+1, tmp_office);
				}
				break;									
		}
			
	}
}


int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	DFS(0,v);
	cout << Min;
	
	return 0;
}

