/* Programmers pccp_mock2_1 
PCCP 모의 2회 2번문항
*/

#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int solution(vector<int> ability, int number) {
    int answer = 0;
    int tmp_count_ability[101]={};
    for(int i=0;i<ability.size();i++){
        tmp_count_ability[ability[i]]++;
        answer+=ability[i];
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> count_ability;
    for(int i=0;i<101;i++){
        if(tmp_count_ability[i]){
            count_ability.push(make_pair(i,tmp_count_ability[i]));
        }
    }
    number*=2;
    int add=0;
    while(number>0){
        int abil=count_ability.top().first;
        int cnt=count_ability.top().second;
        if(cnt>=number){
            return answer+abil*number;
        }else{
            answer+=cnt*abil;
            number-=cnt;
            count_ability.pop();
            if(add){//이전 add 있으면 사용, cnt 1개사용
                count_ability.push(make_pair(add+abil,2));
                cnt--;
                add=0;
            }//add는 이제 0, cnt 1개사용
            if(cnt%2){//홀수개이면 하나 add로
                add=abil;
                cnt--;
            }//cnt는 이제 짝수 또는 0
            if(cnt){//0은 안함 
                count_ability.push(make_pair(abil+abil,cnt));
            }


        }
    }
    return answer;
}