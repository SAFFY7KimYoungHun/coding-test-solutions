/* Programmers pccp_mock2_1 
PCCP 모의 2회 1번문항
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string command) {
    vector<int> answer(2,0);
    vector<vector<int>> rl(4,vector<int>(2,0));
    rl[0][1]=1;
    rl[1][0]=1;
    rl[2][1]=-1;
    rl[3][0]=-1;
    int pos=0;
    for(int i=0;i<command.length();i++){
        if(command[i]=='R'){
            pos++;
            pos%=4;
        }else if(command[i]=='L'){
            pos+=3;
            
            pos%=4;
        }else if(command[i]=='G'){
            answer[0]+=rl[pos][0];
            answer[1]+=rl[pos][1];
        }else{

            answer[0]-=rl[pos][0];
            answer[1]-=rl[pos][1];
        }
    }
    return answer;
}