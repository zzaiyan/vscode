#include <bits/stdc++.h>
using namespace std;

int main() {
  printf("Hello iPhone!\n");
  int v = __cplusplus;
  printf("std = c++%d%d\n", v / 1000 % 10, v / 100 % 10);
  cout << v << endl;

  string inBuf;

  set<string> st;
  while (cin >> inBuf) {
    if (inBuf.size() <= 1)
      break;
    st.insert(inBuf);
  }
  int cnt = 0;
  for (auto i : st) {
    cout << i << ", " << cnt++ << endl;
  }

  return 0;
}
