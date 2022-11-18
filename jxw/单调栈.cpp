#include <bits/stdc++.h>
using namespace std;
using Stack = stack<int>;

class MonoStack : public Stack {
public:
  void push(int x) {
    while (size() && top() >= x)
      pop();
    Stack::push(x);
  }
};

using List = deque<int>;
class MonoQueue : public List {
public:
  void push(int x) {
    while (size() && back() >= x)
      List::pop_back();
    List::push_back(x);
  }
  int pop() {
    int t = back();
    List::pop_back();
    return t;
  }
};
