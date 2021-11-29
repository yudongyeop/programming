#include <iostream>
#include <cstring>

//¿ÏÀüÅ½»ö solution
 
using namespace std;

int N,M;
int paper[500][500];
bool visited[500][500];
int Max = 0;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void search(int x, int y, int seq, int sum) {
	visited[x][y] = true;

	if (seq == 3) {
		if (Max < sum) Max = sum;
		return;
	}
	
	for (int i=0; i<4; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if(visited[nx][ny] == true) continue;
		
		search(nx, ny, seq+1, sum+paper[nx][ny]);
		visited[nx][ny] = false;	
	}		
}
void shape1(int x, int y)
{
    int sum = 0;
    sum = paper[x][y] + paper[x][y+1] + paper[x][y+2] + paper[x-1][y+1];
    if (sum > Max) Max = sum;
}

void shape2(int x, int y)
{
    int sum = 0;
    sum = paper[x][y] + paper[x][y+1] + paper[x][y+2] + paper[x+1][y+1];
    if (sum > Max) Max = sum;
}
 
void shape3(int x, int y)
{
    int sum = 0;
    sum = paper[x][y] + paper[x+1][y] + paper[x+2][y] + paper[x+1][y+1];
    if (sum > Max) Max = sum;
}

void shape4(int x, int y)
{
    int sum = 0;
    sum = paper[x][y] + paper[x-1][y+1] + paper[x][y+1] + paper[x+1][y+1];
    if (sum > Max) Max = sum;
}

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> paper[i][j]; 
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			memset(visited, false, sizeof(visited));
			search(i,j,0,paper[i][j]);
			if (i-1>=0 && j+2<M) shape1(i, j);
            if (j+2<M && i+1<N) shape2(i, j);
            if (i+2<N && j+1<M) shape3(i, j);
            if (i+1<N && i-1>= 0 &&j+1<M) shape4(i, j);
		}
	}
	cout << Max;
	
}
