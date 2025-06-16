//#include <iostream>
//#include <vector>
//#include <climits>
//using namespace std;
//
//int dx[] = { -1, 0, 1, 0 };
//int dy[] = { 0, 1, 0, -1 };
//int cnt = 0;
//const int N = 100;
//vector<vector<bool>> visited(N, vector<bool>(N));
//
//void dfs(int x, int y, int stepsRemain) {
//	if(stepsRemain == 0) {
//		cnt++;
//		return;
//	}
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (!visited[nx][ny]) {
//			visited[nx][ny] = true;
//			dfs(nx, ny, stepsRemain - 1);
//			visited[nx][ny] = false; // 回溯
//		}
//	}
//}
//
//int main() {
//	cout << "請輸入步數(必須是正整數, 且小於22): ";
//	int n;
//	cin >> n;
//	int start = N / 2;
//	visited[start][start] = true;
//	dfs(start, start, n);
//	cout << "自避行走總共有 " << cnt << " 種走法" << endl;
//	return 0;
//}