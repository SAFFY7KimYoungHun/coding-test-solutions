#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    stack<int> S;
    cin>>N;
    string out;
    for(int n=0;n<N;n++){
        int inp;
        cin>>inp;
        switch(inp){
            case 1:
                int X;
                cin>>X;
                S.push(X);
                break;
            case 2:
                if(S.size()>0){
                    out+=S.top()+"\n"
                    S.pop();
                }else{
                    out+="-1\n";
                }
                break;
            case 3:
                out+=to_string((int)S.size())+"\n";
                break;
            case 4:
                out+=S.size()?"0\n":"1\n";
                break;
            case 5:
                out+=S.size()?"0\n":"-1\n";
                cout<<(S.size()?S.top():-1)<<endl;
                break;
        }
    }
}