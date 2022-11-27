#include <bits/stdc++.h>
using namespace std;

class RMB {
  int yuan, jiao;

public:
  RMB(int a = 0, int b = 0) : yuan(a), jiao(b) {}
  void show() { cout << yuan << " 元 " << jiao << " 角\n"; }
  RMB operator+(RMB &a) {
    RMB t(yuan + a.yuan, jiao + a.jiao);
    if (t.jiao >= 10) {
      t.yuan += t.jiao / 10, t.jiao %= 10;
    }
    return t;
  }
  bool operator>(RMB &a) {
    if (yuan != a.yuan)
      return yuan > a.yuan;
    return jiao > a.jiao;
  }
};

int main() {
  RMB a(3, 5), b(2, 7), c;
  a.show();
  b.show();
  c = a + b;
  c.show();
  cout << (a > b ? "a > b" : "a <= b") << endl;

  return 0;
}