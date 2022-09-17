#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
int top, stk[N];

void push(int x) {
  stk[++top] = x;
}

int pop() {
  return stk[top--];
}

int query() {
  return stk[top];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  while (n--) {
    int now;
    cin >> now;
    while (top && query() >= now)
      pop();
    if (top)
      cout << query() << " ";
    else
      cout << -1 << " ";
    push(now);
  }
  cout << endl;
  return 0;
}