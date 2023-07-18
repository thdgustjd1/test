#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
using namespace std;

int n, m;
int answer;
char mp[54][54];
int visited[54][54];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0, -1 };
int dp[54][54];



int go(int y, int x) {
	int &ret = dp[y][x];
	if (ret)return ret;
	visited[y][x] = 1;
	int num = mp[y][x] - '0';
	for (int i = 0; i < 4; i++) {
		int ny = y + num * dy[i];
		int nx = x + num * dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
			continue;
		}
		if (visited[ny][nx] == 1) {
			ret = 987654321;
			break;
		}
		if (mp[ny][nx] == 'H') {
			continue;
		}
		ret = max(go(ny, nx) + 1, ret);
		
	}
	visited[y][x] = 0;

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
		}
	}

	int answer = go(0, 0);
	
	if (answer >= 987654321) {
		cout << -1;
	}
	else {
		cout << answer + 1;
	}


	
}
