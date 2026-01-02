/*
[문제]
- 제목: 계단 수
- 출처: Baekjoon
- 난이도: 골드 1

[풀이]
-
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000000;

int main() {
    int N;
    cin >> N;

    // dp[length][last_digit][mask]
    static int dp[101][10][1024];
    
    // 초기값: 길이 1, 숫자 1~9
    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }
    for (int len = 1; len < N; len++) {
        for (int last = 0; last <= 9; last++) {
            for (int mask = 0; mask < 1024; mask++) {
                int cur = dp[len][last][mask];
                if (cur == 0) continue;

                // 다음 숫자: last - 1
                if (last > 0) {
                    int next = last - 1;
                    int nmask = mask | (1 << next);
                    dp[len + 1][next][nmask] =
                        (dp[len + 1][next][nmask] + cur) % MOD;
                }

                // 다음 숫자: last + 1
                if (last < 9) {
                    int next = last + 1;
                    int nmask = mask | (1 << next);
                    dp[len + 1][next][nmask] =
                        (dp[len + 1][next][nmask] + cur) % MOD;
                }
            }
        }
    }

    long long answer = 0;
    for (int last = 0; last <= 9; last++) {
        answer = (answer + dp[N][last][1024-1]) % MOD;
    }
    cout << answer << '\n';
    return 0;
}