#include <bits/stdc++.h>
using namespace std;

int main() {
  printf("Hello iPhone!\n");
  int v = __cplusplus;
  printf("std = c++%d%d\n", v / 1000 % 10, v / 100 % 10);
  cout << v << endl;
  // for (int i = 0; i < 8; i++) {
  //   cout << "(str[i*8 + " << 8 - (i) << "] - '0') * ";
  //   cout << (1 << i);
  //   cout << " + ";
  // }
  double str;
  vector<double> out;
  int cnt = 0;
  while (cin >> str) {
    out.push_back(str * 2);
  }
  for (auto&& i : out) {
    cout << i << ", ";
  }
  return 0;
}