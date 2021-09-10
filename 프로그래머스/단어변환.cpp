#include <string>
#include <vector>

using namespace std;

int g_answer;

void search(string begin, string target, vector<string> words) {
    bool find = false;
    for (int i=0; i<words.size(); i++) {
        int cnt = 0;
        if(words[i] != "-1") { 
            for (int j=0; j<begin.size(); j++) {
                if(begin[j] != words[i][j]) cnt ++;
            }
        }
        if (cnt == 1) {
            begin = words[i];
            g_answer++;
            words[i] = "-1";
            find = true;
            break;
        }
    }
    if (begin == target) return;
    if (find == false) {
        g_answer = 0;
        return;
    }
    search(begin, target, words);
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    search(begin, target, words);
    answer = g_answer;
    return answer;
}
