/*
출처: BOJ 28278 _스택 구현 문제 (실버4)

주제:
스택 자료구조 구현

링크:
https://www.acmicpc.net/problem/28278

풀이 아이디어:
- C++ STL stack 사용
- 명령어에 따라 push, pop, size, empty, top 동작 수행
- 출력은 string에 모아 마지막에 한번에 출력

시간/공간 복잡도:
- 시간: O(N)
- 공간: O(N)

메모(실수/개선):
- cin/cout 속도 향상 위해 ios::sync_with_stdio(false), cin.tie(NULL) 사용 고려
- 출력 시 endl 대신 '\n' 사용
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    stack<int> S;
    cin>>N;

    string out;
    for(int n=0;n<N;n++){
        int inp;
        cin>>inp;
        switch (inp) {
            case 1: {
                int X;
                cin >> X;
                S.push(X);
                break;
            }
            case 2:
                if (!S.empty()) {
                    out += to_string(S.top());
                    out += '\n';
                    S.pop();
                } else {
                    out += "-1\n";
                }
                break;
            case 3:
                out += to_string((int)S.size());
                out += '\n';
                break;
            case 4:
                out += S.empty() ? "1\n" : "0\n";
                break;
            case 5:
                out += S.empty() ? "-1\n" : (to_string(S.top()) + "\n");
                break;
        }
    }
    cout << out;
    return 0;
}