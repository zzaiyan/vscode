#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void move(int n, char a = 'A', char b = 'B', char c = 'C') {
  if (n == 1) // 当圆盘数为1时，直接从a移动到b
  {
    cout << ++cnt << " :  ";
    cout << a << " -> " << c << endl;
  } else {
    move(n - 1, a, c, b); // 把上面的n-1个圆盘，从a经过c移动到b
    cout << ++cnt << " :  ";
    cout << a << " -> " << c << endl; // 把第n个圆盘从a移动到c
    move(n - 1, b, a, c); // 把那n-1块个圆盘，从b经过a移动到c
  }
}

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);

  int n;
  cin >> n;

  move(n);

  return 0;
}
