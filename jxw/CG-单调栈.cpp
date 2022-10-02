#include <iostream>
#include <stack>
using namespace std;
struct Node {
  long n = -1;
  int tag = -1;
};
long Fibnacci(long n) {
  int sum = 0;
  stack<Node> s;
  Node w;

  do {
    do {
      // w = {n, 1};
      w.n = n, w.tag = 1;
      s.push(w);
    } while (--n >= 0);

    while (s.size()) {
      w = s.top();
      s.pop();
      if (w.n <= 1)
        sum += w.n;
      else if (w.tag == 1) {
        w.tag = 2;
        s.push(w);
        n = w.n - 2;
        break;
      }
    }
  } while (s.size());

  return sum;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cout << Fibnacci(i) << endl;
}