/*
[문제]
- 제목: 올바른 괄호의 갯수
- 출처: Programmers
- 난이도: 4

[풀이]
-
*/
#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(int n) {
    int answer = 0;
    queue<pair<int,int>>queue_pair;//(개수, )개수
    queue_pair.push(make_pair(1,0));
    while(!queue_pair.empty()){
        pair<int,int> parinow[2]={queue_pair.front(),queue_pair.front()};
        queue_pair.pop();
        parinow[0].first+=1;
        parinow[1].second+=1;
        if(parinow[0].first<=n){
            queue_pair.push(parinow[0]);
        }
        if(parinow[1].second<=parinow[1].first){
            if(parinow[1].second==n){
                answer++;
                continue;
            }
            queue_pair.push(parinow[1]);
        }
    }
    return answer;
}