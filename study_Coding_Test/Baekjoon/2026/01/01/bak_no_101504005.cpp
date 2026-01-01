#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main(void){

    int N; cin >> N;
    priority_queue<pair<int,int>> pq; // (-abs(x), -x)

    while (N--) {
        int x; cin >> x;
        if (x != 0) {
            pq.push({-abs(x), -x});
        } else {
            if (pq.empty()) cout << 0 << '\n';
            else { cout << -pq.top().second << '\n'; pq.pop(); }
        }
    }
}