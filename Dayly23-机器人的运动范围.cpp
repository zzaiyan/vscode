#include <bits/stdc++.h>
using namespace std;

const int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int k, m, n, grid[55][55], cnt;

int getSum(int x, int y) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  while (y) {
    ret += y % 10;
    y /= 10;
  }
  return ret;
}

void bfs(int x, int y) {
  if (x < 0 || x >= m || y < 0 || y >= n || getSum(x, y) > k || grid[x][y])
    return;
  // printf("x=%d,y=%d\n", x, y);
  grid[x][y]++;
  bfs(x + 1, y), bfs(x, y + 1);
}

int main() {
  cin >> k >> m >> n;
  bfs(0, 0);

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      if (grid[i][j])
        cnt++;
    }
  cout << cnt << endl;
  // for (int i = 0; i < 4; i++)
  //   cout << dir[i][0] << ' ' << dir[i][1] << endl;
  return 0;
}