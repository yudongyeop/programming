#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int cnt;
string tmp;
vector<long long> ans;

int main(void) {
	cin >> N;
	vector<bool> v(10,1);
	
	if (N==0) {
		cout << "0";
		return 0;
	}
	
	for (int i=0; i<v.size(); i++) {
		v[i] = 0;
		//if (cnt > N) break;
		
		do {
			string tmp = "";
			for (int i=v.size()-1; i>=0; i--) {
				if (v[i] == 0) {
					cnt++;
					tmp+= to_string(i);
				}
			}
			
			cout << tmp << endl;
			ans.push_back(stoll(tmp));
		} while (next_permutation(v.begin(), v.end()));
	
	}
	
	sort(ans.begin(), ans.end());
	if (ans.size() < N) {
		cout << "-1";
		return 0;
	}
	if (ans[N] == 0) cout << "-1";
	else cout << ans[N];
		
	return 0;
}
