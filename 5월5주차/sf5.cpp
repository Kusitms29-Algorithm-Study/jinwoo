/**
 * 5번 문제
 * 제한이 없는 R,C
 * 나이트가 (0,0)에서 시작하여
 * 모든 칸을 몇 번만에 밟을수 있는지 출력
*/
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#define pii pair<int, int>
#define piii pair<pii, int>
#define mp make_pair
#define ll long long

using namespace std;

int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int R, C;
int visited[5000][5000] = {0};

// r,c,depth번째 방문
// bfs
void solve(int r, int c, int depth) {
  queue<piii> q;
  q.push(mp(mp(r, c), depth));
  visited[r][c] = depth;

  while (!q.empty()) {
    int qs = q.size();
    for (int i = 0; i < qs; i++) {
      piii deq = q.front();
      q.pop();
      int deqR = deq.first.first;
      int deqC = deq.first.second;
      int dep = deq.second;

      for (int i = 0; i < 8; i++) {
        int nr = deqR + dy[i];
        int nc = deqC + dx[i];
        if (nr < 0 || nc < 0 || nr >= R || nc >= C)
          continue;
        if (visited[nr][nc] == -1) {
          q.push(mp(mp(nr, nc), dep + 1));
          visited[nr][nc] = dep + 1;
        }
      }
    }
    depth += 1;
  }

}

int main() {
  cin >> R >> C;
  if (R < 2 || C < 2) {
    cout << -1;
    return 0;
  }

  if (R - int(R) != 0 || R - int(R) != 0) {
    cout << -1;
    return 0;
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++)
      visited[i][j] = -1;
  }

  solve(0, 0, 0);

  int ans = -1;
  char tf = 'T';
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      ans = max(ans, visited[i][j]);
      if (visited[i][j] == -1)
        tf = 'F';
    }
  }

  cout << tf << ans;
}
