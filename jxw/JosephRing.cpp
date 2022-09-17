#include <bits/stdc++.h>
using namespace std;
// 模拟循环队列
queue<int> que;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    que.push(i);

  while (que.size() > 1) {
    int times = (m - 1) % que.size();
    while (times-- > 0) {
      int x = que.front();
      que.pop();
      que.push(x);
    }
    // cout << que.front() << ' ';
    que.pop();
  }

  cout << que.front() << endl;

  return 0;
}