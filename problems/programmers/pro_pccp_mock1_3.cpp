/* Programmers pccp_mock1_3 
PCCP 모의 1회 3번문항
*/
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    //M : 4^(N-1)
    //N회차 M번
        //N-1회차의 M/4의 자가수분 결과
    //쿼리의 개수가 작으니까 개별 쿼리에서 찾는게 맞음. 전체 기억하기엔 너무 커짐.
    for(int i=0;i<queries.size();i++){
        int N=queries[i][0]-1;
        if(N==0){
            answer.push_back("Rr");
            answer.push_back(tmp);
            break;
        }
        //N을 하나 감소시켜서 몇번끼리 교배인지 확인
        int M=queries[i][1]-1;
        vector<int> selected(N+1,0);
        for(int n=N;n>=1;n--){
            selected[n]=M%4;
            M/=4;
        }
        string tmp="Rr";
        for(int n=1;n<=N;n++){
            if(selected[n]==0){
                tmp="RR";
                break;
            }else if(selected[n]==3){
                tmp="rr";
                break;
            }
        }
        answer.push_back(tmp);
    }
    return answer;
}