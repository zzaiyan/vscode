#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
int head, tail, que[N];

void push(int x) {
  que[++tail] = x;
}

int pop() {
  return que[++head];
}

bool empty() {
  return tail == head;
}

int query() {
  return que[head + 1];
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