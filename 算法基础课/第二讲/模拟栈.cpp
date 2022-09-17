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

bool empty() {
  return top == 0;
}

int query() {
  return stk[top];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int m;
  cin >> m;

  string op;
  while (m--) {
    cin >> op;
    if (op == "push") {
      int x;
      cin >> x;
      push(x);

    } else if (op == "pop") {
      pop();

    } else if (op == "empty") {
      cout << (empty() ? "YES" : "NO") << "\n";

    } else if (op == "query") {
      cout << query() << "\n";
    }
  }
  return 0;
}