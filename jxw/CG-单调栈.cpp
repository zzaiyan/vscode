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
    do {  // 左孩子依此入栈
      w.n = n, w.tag = 1;
      s.push(w);
    } while (--n >= 0);

    while (s.size()) {
      w = s.top();
      s.pop();       // 取出栈顶元素
      if (w.n <= 1)  // 处理叶子节点
        sum += w.n;
      else if (w.tag) {  // 处理左孩子
        w.tag = 0;
        s.push(w);  // 将对应的右孩子压栈
        n = w.n - 2;
        break;  // 处理完后退出
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