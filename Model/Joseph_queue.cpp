#include <bits/stdc++.h>
using namespace std;
int n, k, a[102];
queue<int> que;
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    que.push(i);
  for (int i = 0; i < k; i++) {
    int num = a[i] % que.size();
    while (num--) {
      int t = que.front();
      que.pop();
      que.push(t);
    }
    cout << que.front() << ' ';
    que.pop();
  }
  return 0;
}