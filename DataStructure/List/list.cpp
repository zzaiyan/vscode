#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct ListNode {
  T date;
  ListNode<int>*pred, *succ;

  ListNode() {
    cout << "default\n";
    pred = nullptr, succ = nullptr;
  }
  ListNode(T& e, ListNode<int>* p = nullptr, ListNode<int>* s = nullptr)
      : date(e), pred(p), succ(s) {}
  ListNode<int>* insertAsPred(const T& e);
  ListNode<int>* insertAsSucc(const T& e);
};

template <typename T = int>
class List {
  int _size;
  ListNode<int>*header, *trailer;

 protected:
  void _init() {
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    trailer->pred = header;
    _size = 0;
  }

 public:
  List() { _init(); }
};

int main() {
  auto obj = new List();
  return 0;
}