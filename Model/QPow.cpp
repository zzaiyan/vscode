#include <bits/stdc++.h>
using namespace std;
int qpow(int a, int b, int p) {
  int ret = 1;
  while (b) {
    if (b & 1)
      ret = 1ll * ret * a % p;
    a = 1ll * a * a % p;
    b >>= 1;
  }
  return ret % p;
}
int main() {
  int base, index;
  const int p = 1e9 + 7;
  cin >> base >> index;
  cout << qpow(base, index, p) << endl;
  return 0;
}