#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> t;

int N, M, K;
vector<t> Tree;
vector<t> Dead;
int Land[10][10];
int A[10][10];

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

bool MyCompare(tuple<int,int,int> a, tuple<int,int,int> b) {
	return get<2>(a) < get<2>(b);
}

void Input() {
	
	cin >> N >> M >> K;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> A[i][j];
			Land[i][j] = 5;	
		}
	}
	
	int x, y, z;
	for (int i=0; i<M; i++) {
		cin >> x >> y >> z;
		Tree.push_back(make_tuple(x-1,y-1,z));
	}
}

void Spring() {
	Dead.clear();
	
	vector<t> Tmp;
	
	for (int i=0; i<Tree.size(); i++) {
		
		int x = get<0>(Tree[i]);
		int y = get<1>(Tree[i]);
		int z = get<2>(Tree[i]);
		
		if (Land[x][y] >= z) {
			Land[x][y]-=z;
			Tmp.push_back(make_tuple(x,y,z+1));
		}
		else {
			Dead.push_back(make_tuple(x,y,z));
		}
	}
	
	Tree.clear();
	
	for (int i=0; i<Tmp.size(); i++) {
		Tree.push_back(Tmp[i]);
	}
		
}

void Summer() {
	for (int i=0; i<Dead.size(); i++) {
		int x = get<0>(Dead[i]);
		int y = get<1>(Dead[i]);
		int z = get<2>(Dead[i]);
		
		Land[x][y]+=(z/2);
	}
}

void Fall() {
	
	vector<t> Tmp;
	vector<t> Tmp2;
	for (int i=0; i<Tree.size(); i++) {
		int z = get<2>(Tree[i]);
		Tmp2.push_back(Tree[i]);
		if (z%5 != 0) continue;
		for (int j=0; j<8; j++) { 
			int nx = get<0>(Tree[i])+dx[j];
			int ny = get<1>(Tree[i])+dy[j];
			if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
			Tmp.push_back(make_tuple(nx,ny,1));
		}
	}
	
	Tree.clear();
	for (int i=0; i<Tmp.size(); i++) Tree.push_back(Tmp[i]);
	
	for (int i=0; i<Tmp2.size(); i++) Tree.push_back(Tmp2[i]);
}

void Winter() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			Land[i][j]+=A[i][j];
		}
	}
}
void Solution() {
	
	sort(Tree.begin(),Tree.end(),MyCompare);
	
	for (int i=0; i<K; i++) {
		Spring();
		Summer();
		Fall();
		Winter();
	}
	
	cout << Tree.size();
}


int main(void) {
	Input();
	Solution();
	return 0;	
}


/* 이 문제를 풀면서 깨달은 점은 vector를 사용할 때 
insert, erase는 시간복잡도가 O(n)이므로 단순 push_back을 사용하는
경우보다 시간복잡도가 훨씬 커질 수 있으므로 왠만해서는
새로 임의의 tmp vector를 만들어서 push_back을 여러번 사용하는게 더 좋다.
 
