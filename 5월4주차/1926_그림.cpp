#include <string.h>

#include <iostream>

using namespace std;
int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int arr[501][501];
int visited[501][501];
int ans = 0;
int sizeCnt = 0;
int cnt = 0;

void dfs(int r, int c) {
  sizeCnt++;
  ans = max(ans, sizeCnt);
  visited[r][c] = 1;

  for (int i = 0; i < 4; i++) {
    int nr = r + dy[i];
    int nc = c + dx[i];
    if (nr < 0 || nc < 0 || nr >= n || nc >= m)
      continue;
    if (visited[nr][nc] == -1 && arr[nr][nc]) {
      dfs(nr, nc);
    }
  }
}

int main() {
  memset(visited, -1, sizeof(visited));

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j] == -1 && arr[i][j]) {
        sizeCnt = 0;
        dfs(i, j);
        cnt++;
      }
    }
  }
  cout << cnt << "\n"
       << ans;
}