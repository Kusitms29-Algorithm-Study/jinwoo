#include <string.h>  //memset

#include <iostream>
using namespace std;
int main() {
  int N;
  int arr[100001];

  // 증가하는, 감소하는 최대 길이
  int dp[2][100001];
  memset(dp, 0, sizeof(int));
  dp[0][0] = dp[1][0] = 1;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < N; i++) {
    if (arr[i - 1] <= arr[i])
      dp[0][i] = dp[0][i - 1] + 1;
    else
      dp[0][i] = 1;

    if (arr[i - 1] >= arr[i])
      dp[1][i] = dp[1][i - 1] + 1;
    else
      dp[1][i] = 1;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, dp[0][i]);
    ans = max(ans, dp[1][i]);
  }

  cout << ans;
}