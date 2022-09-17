#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack : public std::vector<T> {
 public:
  void push(T&& e) {
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~&& push.\n";
    std::vector<T>::emplace_back(std::forward<T>(e));
  }
  const T& pop() {
    T temp = std::vector<T>::operator[](std::vector<T>::size() - 1);
    std::vector<T>::pop_back();
    return temp;
  }
};

int cnt = 0;

class Test {
 public:
  int val;

  ~Test() { cout << "----------------desruction, val = " << val << endl; }

  Test() : val(0) {
    cout << "default construct with ";
    cout << "val = " << val << endl;
  }

  Test(const int& e) : val(e) {
    cout << "common construct with ";
    cout << "val = " << val << endl;
  }

  Test(const Test& T) : val(T.val) {
    cout << "& copy consruct with ";
    cout << "val = " << val << endl;
    cout << "copy time: " << ++cnt << endl;
  }

  Test(Test&& T) noexcept : val(T.val) {
    cout << "&& move consruct with ";
    cout << "val = " << val << endl;
  }
};

int main() {
  Stack<Test> S;
  // vector<Test> S;
  int n;
  cin >> n;
  S.reserve(n);

  cout << S.capacity() << endl;
  for (int i = 0; i < n; i++) {
    int t = i + 1;
    S.push(t);
    // cout << t << " ";
  }
  cout << "----------------------ending build\n";
  // while (S.size())
  //   S.pop();
  cout << endl;
  return 0;
}