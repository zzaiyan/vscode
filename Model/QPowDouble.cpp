#include <bits/stdc++.h>
using namespace std;

double qpow(double base, int idx, bool neg) {
  double ret = 1;
  while (idx) {
    if (idx & 1)
      ret *= base;
    base = base * base;
    idx >>= 1;
    if (neg && ret > 1e5)
      break;
  }
  return ret;
}

double Power(double base, int exponent) {
  if (base == 0)
    return 0;
  int neg = 0;
  double now = base;
  if (exponent < 0)
    neg = 1, exponent *= -1;
  auto ans = qpow(base, exponent, neg);
  if (neg)
    ans = 1 / ans;
  return ans;
}

int main() {
  double a;
  int b;
  cin >> a >> b;
  auto out = Power(a, b);
  cout << out << endl;
  return 0;
}