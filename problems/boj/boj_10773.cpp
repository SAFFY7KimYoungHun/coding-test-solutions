#include <iostream>
#include <stack>
using namespace std;
int main() {
    int K;
    long long sum=0;
    stack<int> S;
    cin>>K;
    for(int k=0;k<K;k++){
        int inp;
        cin>>inp;
        if(inp){
            sum+=inp;
            S.push(inp);
        }else{
            sum-=S.top();
            S.pop();
        }
    }
    cout<<sum;
    return 0;
}