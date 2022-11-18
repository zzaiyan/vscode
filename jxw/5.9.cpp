#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
};

void show(Node *first) {
  for (auto p = first; p != nullptr; p = p->next)
    cout << p->data << ' ';
  cout << endl;
}

Node *reverse(Node *head) {
  // 递归出口
  if (head->next == nullptr)
    return head;
  Node *last = reverse(head->next);
  head->next->next = head;
  head->next = nullptr;
  return last;
}

int main() {
  int n;
  cin >> n;
  // 建立链表
  Node *first = nullptr, *last;
  while (n--) {
    auto newNode = new Node{n + 1, first};
    first = newNode;
  }
  // 定位 last 指针
  for (last = first; last->next != nullptr; last = last->next)
    ;
  // 遍历输出链表内容
  show(first);
  reverse(first);
  show(last);

  return 0;
}