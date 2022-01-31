#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<int,int> p;
typedef tuple<int,int,int> t;

int M, N;
int max_size = 0;
int Room;
int Size;
vector<int> Size_list;

char Castle[50][50];
int Visit[50][50];

int remove_size = 0;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
void Input() {
	int a;
	cin >> M >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> a;
			Castle[i][j] = static_cast<char>(a);
		}
	}	
}

string Binary(char n) {
	string str = "";
	for (int i=0; i<4; i++) {
		char tmp = n%2;
		str += to_string(tmp);
		n/= 2;
	}
	return str;
}

void BFS(int x, int y, int num) {
	queue<p> q;
	q.push(make_pair(x,y));
	Visit[x][y] = num;
	int size = 1;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		string str = Binary(Castle[x][y]);
		
		for (int i=0; i<4; i++) {
			if (str[i] == '0') {
				int nx = x+dx[i];
				int ny = y+dy[i];
				
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				
				if (Visit[nx][ny] == 0) {
					Visit[nx][ny] = num;
					q.push(make_pair(nx,ny));
					size++;
				}
			}
		}
	}
	Size_list.push_back(size);	
	if (Size <= size) Size = size;
}

void BFS2() { 
	int start_x = 0;
	int start_y = 0;
	int start_num = Visit[0][0];
	queue<t> q;
	q.push(make_tuple(start_x,start_y,start_num));
	
	Visit[0][0] = 0;
	
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cur_num = get<2>(q.front());
		
		q.pop();
		
		for (int i=0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			
			if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
			int n_num = Visit[nx][ny];
			if (Visit[nx][ny] != 0) {
				Visit[nx][ny] = 0;
				
				if (n_num != cur_num) {
					if (max_size <= Size_list[n_num-1] + Size_list[cur_num-1]) max_size = Size_list[n_num-1] + Size_list[cur_num-1];
				}
				q.push(make_tuple(nx,ny,n_num));
			}	
		}
	}	
}

void Solve() {
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (Visit[i][j] == 0) {
				Room++;
				BFS(i,j, Room);
			}
		}
	}
	BFS2();
	
	cout << Room << '\n';
	cout << Size << '\n';
	cout << max_size;
}

int main(void) {
	Input();
	Solve();
	return 0;
}
