#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <cstring>
 
using namespace std;
int K;
int wheel[4][8];
int visit[4];

typedef pair<int,int> p;

void rotate(int cwn, int cdi) {
	if (cdi == 1) { 
		int tmp = wheel[cwn-1][7];
		int temp;
		for (int i=7; i>0; i--) wheel[cwn-1][i] = wheel[cwn-1][i-1];
		wheel[cwn-1][0] = tmp;		
	}
	
	if (cdi == -1) {
		int tmp2 = wheel[cwn-1][0];
		for (int i=0; i<7; i++) wheel[cwn-1][i] = wheel[cwn-1][i+1];
		wheel[cwn-1][7] = tmp2; 
	}	
}

void spin(int wn, int di) {
	memset(visit,0,sizeof(visit));
	queue<p> q;
	q.push(make_pair(wn,di));
	vector<p> rotate_list;	
	visit[wn-1] = true;
	while(!q.empty()) {
		int cwn = q.front().first;
		int cdi = q.front().second; 
		q.pop();
		rotate_list.push_back(make_pair(cwn,cdi));
		if (cwn != 1 && wheel[cwn-2][2] != wheel[cwn-1][6] && visit[cwn-2]==0) {
			q.push(make_pair(cwn-1,-cdi));
			visit[cwn-2] = true;	
		}
		
		if (cwn != 4 && wheel[cwn][6] != wheel[cwn-1][2] && visit[cwn]==0) {
			q.push(make_pair(cwn+1,-cdi));
			visit[cwn] = true;	
		}
	}
	for (int i=0; i<rotate_list.size(); i++) rotate(rotate_list[i].first, rotate_list[i].second);	
	
}


int main(void) {
	string tmp;
	for (int i=0; i<4; i++) {
		cin >> tmp; 
		for (int j=0; j<8; j++) {
			wheel[i][j] = tmp[j]-'0';
		}
	}
	cin >> K;
	for (int i=0; i<K; i++) {
		int wn;
		int di; 
		cin >> wn >> di;
		
		if (di == 1) spin(wn,1); // 시계 방향 (1)
		else spin(wn,-1); // 반시계 방향 (-1) 
		
		memset(visit,0,sizeof(visit));
	}
	
	int answer = 0;
	int score =  1; 
	for (int i=0; i<4; i++) {
		if (wheel[i][0] == 1) answer+= score;
		score*=2;
	}
	cout << answer;	
}
