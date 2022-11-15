#include <iostream>
using namespace std;
//一个C++11利用模板特化循环展开参数包的办法
template <typename FUNC> //这种办法需要有一个这样的同名终止递归函数
void deal(FUNC func) {
  cout << "end" << endl;
}
template <
    typename FUNC, typename head,
    typename... T> //这个函数的作用是，使用第一个参数所表示的函数，来处理后面所有数字
void deal(FUNC func, head _head, T... args) {
  cout << "共有参数：" << sizeof...(args) << "个-------" << _head << "->"
       << func(_head) << endl;
  deal(func, args...);
}
//另一个利用C++11的可变长列表初始化来实现的参数包展开
template <typename FUNC, typename T> void deal2(FUNC func, T num) {
  cout << num << "->" << func(num) << endl;
}
template <typename FUNC, typename... T> void expand(FUNC func, T... args) {
  int arr[] = {(deal2(func, args), 0)...};
  //利用括号和逗号表达式展开参数包
  // arr中全部是0，因为编译器对于括号来说，他会先处理括号，在括号里面，按照逗号表达式依次求解，于是他先展开了deal2,然后把0填入数组，其实这个0是没有意义的
  for (int i = 0; i < sizeof...(args); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int s(int a) { return a * 2; }
int main() {
  cout << "way 1:" << endl;
  deal(s, 1, 2, 3, 4, 5, 6, 7);
  cout << "way 2:" << endl;
  expand(s, 1, 2, 3, 4, 5, 6, 7);
  return 0;
}