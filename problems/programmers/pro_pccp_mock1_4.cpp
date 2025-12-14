/* Programmers pccp_mock1_4 
PCCP 모의 1회 4번문항
*/
#include <string>
#include <vector>
#include <algorithm>
//#include <queue>
using namespace std;

int answer;
vector<bool> used;
//단순 for문 보이는 계산횟수를 줄이려면 queue가 맞다.
//하지만 push횟수가 늘어나 손해.
//시험 결과에는 영향없었지만 실제라면 클수도
void dfs(int col, int sum, const vector<vector<int>>& ability) {
    if (col == ability[0].size()) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < ability.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            dfs(col + 1, sum + ability[i][col], ability);
            used[i] = false;
        }
    }
}

int solution(vector<vector<int>> ability) {
    answer = 0;
    used.assign(ability.size(), false);
    dfs(0, 0, ability);
    return answer;
}