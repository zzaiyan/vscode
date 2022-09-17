#include <bits/stdc++.h>
using namespace std;
#define Node ListNode<Unit>

template <typename T>
struct ListNode {
  T val;
  ListNode* next;
  ListNode(T x) : val(x), next(nullptr) {}
};

struct Unit {
  int val, index;
};

class Multy {
  Node* head = nullptr;

 public:
  Multy() = default;
  Multy(Multy& m1, Multy& m2);
  void creat(int n) {
    cout << "请输入 x^" << n << " 项的系数：";
    int x;
    cin >> x;
    head = new Node(Unit{x, n});
    auto p = head;
    while (n--) {
      cout << "请输入 x^" << n << " 项的系数：";
      cin >> x;
      auto t = new Node(Unit{x, n});
      p->next = t;
      p = p->next;
    }
  }
  void show() {
    auto p = head;
    while (p != nullptr) {
      if (p->val.index && p->val.val)
        cout << p->val.val << '*' << "x^" << p->val.index;
      else if (p->val.val)
        cout << p->val.val;
      if (p->next != nullptr && p->next->val.val)
        cout << " + ";
      p = p->next;
    }
    putchar('\n');
  }
};

Multy::Multy(Multy& m1, Multy& m2) {
  int n1 = 1, n2 = 1;
  Node* p = nullptr;
  p = m1.head;
  while (p->next != nullptr)
    ++n1, p = p->next;
  p = m2.head;
  while (p->next != nullptr)
    ++n2, p = p->next;
  auto p1 = m1.head, p2 = m2.head;
  if (n1 > n2) {
    head = new Node({p1->val.val, p1->val.index});
    --n1, p1 = p1->next;
  } else if (n1 < n2) {
    head = new Node({p2->val.val, p2->val.index});
    --n2, p2 = p2->next;
  } else {
    head = new Node({p1->val.val + p2->val.val, p1->val.index});
    --n1, --n2, p1 = p1->next, p2 = p2->next;
  }
  p = head;
  while (n1 > n2) {
    p->next = new Node({p1->val.val, p1->val.index});
    --n1, p1 = p1->next, p = p->next;
  }
  while (n2 > n1) {
    p->next = new Node({p2->val.val, p2->val.index});
    --n2, p2 = p2->next, p = p->next;
  }
  while (n1-- && n2--) {
    p->next = new Node({p1->val.val + p2->val.val, p1->val.index});
    p1 = p1->next, p2 = p2->next, p = p->next;
  }
}

int main() {
  int n;
  Multy multy1, multy2;

  cout << "请输入第一个多项式的最高次数：";
  cin >> n;
  multy1.creat(n);

  cout << "\n请输入第二个多项式的最高次数：";
  cin >> n;
  multy2.creat(n);

  Multy multy3(multy1, multy2);

  cout << "\n----第一个多项式----\n";
  multy1.show();
  cout << "\n----第二个多项式----\n";
  multy2.show();
  cout << "\n----两个多项式的和----\n";
  multy3.show();

  return 0;
}