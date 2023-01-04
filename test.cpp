#include <bits/stdc++.h>
using namespace std;

template <typename... Args> unsigned int length(Args... args) {
  return sizeof...(args);
}

void print() { ; }
template <typename T, typename... Args> void print(T head, Args... args) {
  std::cout << head << (sizeof...(args) > 0 ? ", " : "");
  print(args...);
}

auto fun() { return tuple{1, 2.5, 'a'}; }

auto test() {
  auto [a, b, c] = fun();
  print(a, b, c);
}

int main() {
  test();
  // printf("Hello iPhone!\n");
  // int v = __cplusplus;
  // printf("std = c++%d%d\n", v / 1000 % 10, v / 100 % 10);
  // cout << v << endl;

  // string inBuf;

  // set<string> st;
  // while (cin >> inBuf) {
  //   if (inBuf.size() <= 1)
  //     break;
  //   st.insert(inBuf);
  // }
  // int cnt = 0;
  // for (auto &&i : st) {
  //   cout << i << ", " << cnt++ << endl;
  // }

  return 0;
}
