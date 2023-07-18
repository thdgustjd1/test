#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int visited[100004], arr[100004], t, n, answer;

void findcycle(int now) {
    visited[now] = -1;
    if (visited[arr[now]] == -1) {
        return;
    }
    else {
        findcycle(arr[now]);
    }
}

void tail(int now) {
    visited[now] = -2;
    if (visited[arr[now]] == 1) {
        tail(arr[now]);
    }
    else {
        return;
    }
}


void cycle(int start, int now) {
    visited[now] = 1;
    if (visited[arr[now]] == 0) {
        cycle(start, arr[now]);
        return;
        //dasdfsasadfasdfsdaf
    }
    
    else { //1ÀÏ¶§
        findcycle(now);
        if (arr[now] != start) {
            tail(start);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {
        memset(visited, 0, sizeof(visited));
        memset(arr, 0, sizeof(arr));
        answer = 0;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                cycle(i, i);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == -2)answer++;
        }

        cout << answer << "\n";
    }

}