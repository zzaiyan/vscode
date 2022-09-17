#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
int n, head, idx, e[N], ne[N];

void init() {
  head = idx++;
  ne[head] = -1;
}

void push_front(int x) {
  int now = idx++;
  e[now] = x;
  ne[now] = ne[head];
  ne[head] = now;
}

void insert(int k, int x) {
  int now = idx++;
  e[now] = x;
  ne[now] = ne[k];
  ne[k] = now;
}

void show() {
  for (int j = ne[head]; j != -1; j = ne[j]) {
    cout << e[j] << " ";
  }
  cout << endl;
}

void remove(int k) {
  if (k > 0) {
    ne[k] = ne[ne[k]];
  } else {
    head = ne[head];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  init();

  cin >> n;

  while (n--) {
    char op;
    cin >> op;
    if (op == 'H') {
      int x;
      cin >> x;
      push_front(x);

    } else if (op == 'I') {
      int k, x;
      cin >> k >> x;
      insert(k, x);

    } else if (op == 'D') {
      int k;
      cin >> k;
      remove(k);
    }
  }

  show();

  return 0;
}