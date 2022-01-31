#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> 
#include <cstring>

using namespace std;

typedef tuple<int,int,int> t;

int Land[10][10];
int give[10][10];
int N, M, K;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

vector<t> tree; // x, y, age
vector<t> Delete; 

bool Mycompare(tuple<int,int,int> a, tuple<int,int,int> b) {
	return (get<2>(a) < get<2>(b));
}

void Input() {
	cin >> N >> M >> K;
	
	int a,b,c;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> a;
			give[i][j] = a;
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			Land[i][j] = 5;
		}
	}
	
	for (int i=0; i<M; i++) {
		cin >> a >> b >> c;
		tree.push_back(make_tuple(a-1,b-1,c));
	}
}

void Spring() {
	
	
	for (int i=0; i<tree.size();) {
		int x = get<0>(tree[i]);
		int y = get<1>(tree[i]);
		int age = get<2>(tree[i]);
		
		//cout << " x : " << x << " y : " << y << " age : " << age << endl;		
		
		if(age <= Land[x][y]) {
			Land[x][y] -= age;
			get<2>(tree[i])++; // Spring
			i++;
		}
		else { // Summer
			Delete.push_back(make_tuple(x,y,age));
			tree.erase(tree.begin()+i);	
		}
	} 
}

void Summer() {
	for (int i=0; i<Delete.size(); i++) {
		int x = get<0>(Delete[i]);
		int y = get<1>(Delete[i]);
		int age = get<2>(Delete[i]);
		
		age /= 2;
		
		Land[x][y] += age;
		
	}
	Delete.clear();
}

void Fall() {
	int size = tree.size();
	
	for (int i=0; i<tree.size(); i++) {
		int x = get<0>(tree[i]);
		int y = get<1>(tree[i]);
		int age = get<2>(tree[i]);
		
		
		if (age % 5 == 0) {
			for (int j=0; j<8; j++) {
				int nx = x+dx[j];
				int ny = y+dy[j];
				if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				tree.insert(tree.begin(), make_tuple(nx,ny,1));
				i++;
				//cout << " nx : " << nx << " ny : " << ny << endl; 
			}
		}
	}
}

void Winter() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			Land[i][j]+=give[i][j];
		}
	}
}

void Output() {
	cout << tree.size();
}


void Solve() {
	
	sort(tree.begin(),tree.end(),Mycompare);
	
	for (int i=0; i<K; i++) {
		Spring();
		Summer();
		Fall();
		Winter();
	}
	
	Output();
}

int main(void) {
	Input();
	Solve();
	
	return 0;	
}
