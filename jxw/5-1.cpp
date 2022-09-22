#include <bits/stdc++.h>
using namespace std;

int main() {
  int i, j, k;
  int n = 10;
  // cin >> i >> j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      k = (2 * n - i - 1) * i / 2 + j;
      if (j >= i)
        cout << k << "\t";
      else
        cout << "\t";
    }
    cout << endl;
  }

  cout << "k = " << k << endl;
}