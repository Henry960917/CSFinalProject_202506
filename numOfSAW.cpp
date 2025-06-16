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
//			visited[nx][ny] = false; // �^��
//		}
//	}
//}
//
//int main() {
//	cout << "�п�J�B��(�����O�����, �B�p��22): ";
//	int n;
//	cin >> n;
//	int start = N / 2;
//	visited[start][start] = true;
//	dfs(start, start, n);
//	cout << "���צ樫�`�@�� " << cnt << " �ب��k" << endl;
//	return 0;
//}