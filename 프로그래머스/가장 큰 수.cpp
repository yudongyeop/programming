#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool mycompare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> strvec;
    string answer = "";
    
    for (int i=0; i<numbers.size(); i++) {
        strvec.push_back(to_string(numbers[i]));
    }
    sort(strvec.begin(), strvec.end(), mycompare);
    for (int i=0; i<strvec.size(); i++) {
        answer += strvec[i];
    }
    if(answer[0] == '0') answer = "0";
    return answer;
}
