#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int N, M;

map<string, vector<p>> room;
vector<string> room_names;
vector<p> possible[50];

void Input() {
	
	cin >> N >> M;
	
	string a;
	
	for (int i=0; i<N; i++) {
		cin >> a;
		
		room_names.push_back(a);
	}
	
	
	int b, c;
	
	for (int i=0; i<M; i++) {
		cin >> a;
		cin >> b >> c;
		room[a].push_back(make_pair(b, c));
	}
}

void Solution() {
	
	sort (room_names.begin(), room_names.end());
	
	for (int i=0; i<N; i++) {
		sort(room[room_names[i]].begin(), room[room_names[i]].end());
	}
	
	for (int i=0; i<N; i++) {
		if (room[room_names[i]].size() == 0) possible[i].push_back(make_pair(9,18));
	}
	
	for (int i=0; i<N; i++) {
		string room_name = room_names[i];
		int start = 9;
		int end = 18;
		for (int j=0; j<room[room_name].size(); j++) {
			end = room[room_name][j].first;
			
			if (start != end) possible[i].push_back(make_pair(start, end));
			
			start = room[room_name][j].second;
			
			if (j == room[room_name].size()-1) {
				if (start != 18) possible[i].push_back(make_pair(start, 18)); 
			}
		}
	}
	 
	for (int i=0; i<N; i++) {
		
		string room_name = room_names[i];
		cout << "Room " + room_name + ":" << '\n';
		int size = possible[i].size();
		if (size == 0) cout << "Not available" << '\n';
		else cout << size << " available:" << '\n';
		for (int j=0; j<possible[i].size(); j++) {
			int a = possible[i][j].first;
			int b = possible[i][j].second;
			string sa;
			string sb;
			
			if (a < 10) sa = "0" + to_string(a);
			else sa = to_string(a);
			
			if (b < 10) sb = "0" + to_string(b);
			else sb = to_string(b);
			 
			cout << sa << "-" << sb << endl;
		}
		if (i < N-1) cout << "-----" << endl;
	}
	
}

void Solve() {
	
	Input();
	Solution();
	
}
int main(void) {
	Solve();
	return 0;
}

