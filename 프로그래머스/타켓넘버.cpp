#include <string>
#include <vector>

using namespace std;

int g_answer = 0;

void search(vector<int> numbers, int target, int num, int next, int sum) {
    sum += next;
    if (num == numbers.size()-1) {
        if(sum == target) g_answer++;
        return;
    }
    search(numbers, target, num+1, -numbers[num+1], sum);
    search(numbers, target, num+1, +numbers[num+1], sum);
}

int solution(vector<int> numbers, int target) {
    search(numbers, target, 0, +numbers[0], 0);
    search(numbers, target, 0, -numbers[0], 0);
    int answer = g_answer;
        
    return answer;
}
