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
	sort(Tree.begin(),Tree.end(),MyCompare);
	Dead.clear();
	
	for (int i=0; i<Tree.size();) {
		int x = get<0>(Tree[i]);
		int y = get<1>(Tree[i]);
		int z = get<2>(Tree[i]);
		
		if (Land[x][y] >= z) {
			Land[x][y]-=z;
			get<2>(Tree[i])++;
			i++;
		}
		else {
			Dead.push_back(make_tuple(x,y,z));
			Tree.erase(Tree.begin()+i);
		}
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
	int size = Tree.size();
	for (int i=0; i<size; i++) {
		int z = get<2>(Tree[i]);
		if (z%5 != 0) continue;
		for (int j=0; j<8; j++) { 
			int nx = get<0>(Tree[i])+dx[j];
			int ny = get<1>(Tree[i])+dy[j];
			if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
			
			Tree.push_back(make_tuple(nx,ny,1));
		}
	}
}

void Winter() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			Land[i][j]+=A[i][j];
		}
	}
}
void Solution() {

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
