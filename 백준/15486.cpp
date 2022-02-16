#include<iostream>
using namespace std;
 
int T[1500002];
int P[1500002];
int DP[1500002];
 
int main(void)
{
    int N;
    cin >> N;
 
    for (int i = 1; i <= N; i++) cin >> T[i] >> P[i];
    
 
    for (int i = N; i >= 1; i--)
    {
        if (i+T[i] > N+1) DP[i] = DP[i + 1];
        
        else DP[i] = max(DP[i+1], P[i]+DP[i+T[i]]);
        
    }
 
    cout << DP[1];
 
    return 0;
}
