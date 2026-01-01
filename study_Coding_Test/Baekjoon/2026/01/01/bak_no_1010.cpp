/*
[문제]
- 제목: 1010
- 출처: Baekjoon
- 난이도: 실버5

[풀이]
-
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        long long result = 1;
        for (int i = 1; i <= N; i++) {
            result = result * (M - N + i) / i;
        }

        cout << result << '\n';
    }
}