#include <bits/stdc++.h>
using namespace std;

vector<int> highDiv(string& a, int b, int& r) {
  vector<int> A, C;
  for (int i = a.size() - 1; i >= 0; i--)
    A.push_back(a[i] - '0');
  r = 0;
  for (int i = A.size() - 1; i >= 0; i--) {
    if (i >= 0)
      r = A[i] + 10 * r;
    C.push_back(r / b);
    r %= b;
  }
  while (C.size() > 1 && C.front() == 0)
    C.erase(C.begin());
  return C;
}

int main() {
  string a;
  int b, res;
  cin >> a >> b;

  auto c = highDiv(a, b, res);

  for (auto i : c)
    cout << i;
  cout << "\n" << res << "\n";

  return 0;
}