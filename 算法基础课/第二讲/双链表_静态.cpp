#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
constexpr int head = 0, tail = 1;
int idx, e[N], l[N], r[N];

void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // head = 0, tail = 1;
  r[head] = tail, l[tail] = head;
  idx = 2;
}

void insert_r(int k, int x) {
  k++;
  int now = idx++;
  e[now] = x;
  r[now] = r[k];
  l[now] = k;
  r[l[now]] = now;
  l[r[now]] = now;
}

void insert_l(int k, int x) {
  k++;
  int now = idx++;
  e[now] = x;
  r[now] = k;
  l[now] = l[k];
  r[l[now]] = now;
  l[r[now]] = now;
}

void push_front(int x) {
  insert_r(head - 1, x);
}

void push_back(int x) {
  insert_l(tail - 1, x);
}

void remove(int k) {
  k++;
  r[l[k]] = r[k];
  l[r[k]] = l[k];
}

void show() {
  for (int now = r[head]; now != tail; now = r[now])
    cout << e[now] << " ";
  cout << endl;
}

int main() {
  init();

  int k, x, n;
  cin >> n;

  string op;
  while (n--) {
    cin >> op;
    if (op == "L") {
      cin >> x;
      push_front(x);

    } else if (op == "R") {
      cin >> x;
      push_back(x);

    } else if (op == "D") {
      cin >> k;
      remove(k);

    } else if (op == "IL") {
      cin >> k >> x;
      insert_l(k, x);

    } else if (op == "IR") {
      cin >> k >> x;
      insert_r(k, x);
    }
    // show();
  }
  show();

  return 0;
}