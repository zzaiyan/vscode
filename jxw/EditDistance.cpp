#include <bits/stdc++.h>
using namespace std;

int leastEdit(string string1, string string2) {
  int m = string1.size(), n = string2.size();
  // vector<vector<int>> dp(m + 1, vector<int>(n + 1));
  int **dp = new int *[m + 1];
  for (int i = 0; i <= m; i++)
    dp[i] = new int[n + 1];

  for (int i = 0; i <= m; i++)
    dp[i][0] = i;
  for (int i = 0; i <= n; i++)
    dp[0][i] = i;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      // 添加 和 删除
      dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
      // 替换 和 do nothing
      dp[i][j] =
          min(dp[i][j], dp[i - 1][j - 1] + (string1[i - 1] != string2[j - 1]));
    }
  }
  int ret = dp[m][n];
  for (int i = 0; i <= m; i++)
    delete[] dp[i];
  delete[] dp;
  return ret;
}

int main() {
  string s1, s2;

  cin >> s1 >> s2;
  cout << leastEdit(s1, s2);

  return 0;
}