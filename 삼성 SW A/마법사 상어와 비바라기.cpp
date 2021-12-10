#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
 
typedef pair<int, int> p;

int N,M; 

int A[50][50];
bool visit[50][50];
int dx[] = {0,0,-1,-1,-1,0,1,1,1}; 
int dy[] = {0,-1,-1,0,1,1,1,0,-1};

int copy_dx[] = {1,1,-1,-1};
int copy_dy[] = {-1,1,1,-1};

vector<p> cmd;
vector<p> cloud;

void Input() {
	cin >> N >> M;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> A[i][j];
		}
	}
	
	int tmp1, tmp2;
	for (int i=0; i<M; i++) {
		cin >> tmp1 >> tmp2;
		cmd.push_back(make_pair(tmp1,tmp2));
	}
	
	cloud.push_back(make_pair(N-1,0));
	cloud.push_back(make_pair(N-1,1));
	cloud.push_back(make_pair(N-2,0));
	cloud.push_back(make_pair(N-2,1));
	visit[N-1][0] = true;
	visit[N-1][1] = true;
	visit[N-2][0] = true;
	visit[N-2][1] = true;
}

void Solve() {
	for (int i=0; i<M; i++) {  //command
		
		memset(visit,false,sizeof(visit));
		
		int d = cmd[i].first;
		int l = cmd[i].second;  

		//stpe 1 (moving cloud)
		for (int j=0; j<cloud.size(); j++) {
			int x = cloud[j].first;
			int y = cloud[j].second;
		
			
			int nx = x;
			int ny = y;
			for (int k = 0; k < l; k++) {
				nx += dx[d];
				ny += dy[d];
				
				if (nx < 0) nx = N-1;
				if (nx >= N) nx = 0;
				if (ny < 0) ny = N-1;
				if (ny >= N) ny = 0;
			}
			

			cloud[j].first = nx;
			cloud[j].second = ny;
			
			//step 2 (raining)
			A[nx][ny]++;
			visit[nx][ny] = true;
			
		}
		
		for (int z=0; z<cloud.size(); z++) { //step 4 (copy cloud)
			int x = cloud[z].first;
			int y = cloud[z].second;
			
			//check diagonal
			
			for (int k=0; k<4; k++) {
				int nx = x+copy_dx[k];
				int ny = y+copy_dy[k];
				
				if (nx >= N || nx < 0 || ny >= N || ny < 0) continue; // Not connected

				if (A[nx][ny] >= 1) A[x][y]++; 
			}
		}
		
		cloud.clear(); //step 3 (remove cloud)
		
		for (int a=0; a<N; a++) { //step 5 (making cloud)
			for (int b=0; b<N; b++) {
				if (A[a][b] >= 2 && visit[a][b] == false) {
					A[a][b] -= 2;
					cloud.push_back(make_pair(a,b));
				}
			}
 		}
	}		
}


void Answer() {
	int sum = 0;
	for (int i=0; i<N; i++) 
		for (int j=0; j<N; j++) sum+= A[i][j];

	cout << sum;
}

int main(void) {
	Input();
	Solve();
	Answer();
	return 0;
}
