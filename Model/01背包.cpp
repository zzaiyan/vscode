#include <bits/stdc++.h>

constexpr int MAXN = 10005;
int N, V, dp[MAXN], v[MAXN], w[MAXN];

int main() {
  scanf("%d%d", &N, &V);
  for (int i = 1; i <= N; i++)
    scanf("%d%d", w + i, v + i);

  for (int i = 1; i <= N; ++i)
    for (int j = V; j >= w[i]; --j)
      dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);

  printf("%d", dp[V]);
  return 0;
}