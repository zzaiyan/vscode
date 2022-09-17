#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 5;
int a[N], q[N], head, tail;
// q[N]存储数组下标

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  head = 0, tail = -1;
  for (int i = 0; i < n; i++) {
    // 维持滑动窗口的大小
    // 当队列不为空(head <= tail) 且 当当前滑动窗口的大小(i - q[head] + 1)>k
    // 滑动窗口的大小(k),队列弹出队列头元素以维持滑动窗口的大小
    if (head <= tail && i - q[head] + 1 > k)
      head++;
    // 构造单调递增队列
    // 当队列不为空(head <= tail)
    // 且当队列队尾元素>=当前元素(a[i])时,那么队尾元素
    // 就一定不是当前窗口最小值,删去队尾元素,加入当前元素(q[++tail] = i)
    while (head <= tail && a[q[tail]] >= a[i])
      tail--;
    q[++tail] = i;
    if (i >= k - 1)
      cout << a[q[head]] << " ";
  }
  cout << "\n";
  // 以上为最小值,接下来求对应的最大值
  head = 0, tail = -1;
  for (int i = 0; i < n; i++) {
    if (head <= tail && i - q[head] + 1 > k)
      head++;
    // 此处的>=替换为<=,镜像执行一次
    while (head <= tail && a[q[tail]] <= a[i])
      tail--;
    q[++tail] = i;
    if (i >= k - 1)
      cout << a[q[head]] << " ";
  }
  cout << "\n";

  return 0;
}