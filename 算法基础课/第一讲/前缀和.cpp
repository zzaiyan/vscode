#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 5;
int a[N], s[N], n, m;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];

  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << s[r] - s[l - 1] << "\n";
  }

  return 0;
}