#include <bits/stdc++.h>
using namespace std;

int main() {
  printf("Hello iPhone!\n");
  int v = __cplusplus;
  printf("std = c++%d%d\n", v / 1000 % 10, v / 100 % 10);
  cout << v << endl;
  for (int i = 0; i < 10; i++) {
    cout << "(str[i*10 + " << i + 1 << "] - '0') * ";
    cout << (1 << i);
    cout << " + ";
  }
  return 0;
}
