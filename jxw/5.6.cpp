#include <bits/stdc++.h>
using namespace std;

list<int> L;

int func(int a, int b) {
  int oldSize = L.size();
  auto l = L.begin(), r = l;
  for (auto p = L.begin(); p != L.end(); p++) {
    if (*p <= a)
      l = p;
    if (*p <= b)
      r = p;
  }
  L.erase(++l, r);
  return oldSize - L.size();
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    L.push_back(i + 1);

  int a, b;
  cin >> a >> b;
  func(a, b);
  for (auto i : L)
    cout << i << ' ';
  cout << endl;

  return 0;
}