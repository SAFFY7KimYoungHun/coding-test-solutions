#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> Near(n+1);
    for(int i=0;i<edge.size();i++){
        Near[edge[i][0]].push_back(edge[i][1]);
        Near[edge[i][1]].push_back(edge[i][0]);
    }
    vector<int> isVisited(n+1,0);
    isVisited[1]=1;
    queue<int> mainQ;
    mainQ.push(1);
    while(1){
        int sizes=mainQ.size();
        if(!sizes) return answer;
        answer=sizes;
        for(int i=0;i<sizes;i++){
            int past=mainQ.front();
            mainQ.pop();
            for(int j=0;j<Near[past].size();j++){
                if(!isVisited[Near[past][j]]){
                    isVisited[Near[past][j]]=1;
                    mainQ.push(Near[past][j]);
                }
            }
        }
    }
    return answer;
}