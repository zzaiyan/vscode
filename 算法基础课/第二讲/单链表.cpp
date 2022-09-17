#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

struct Node {
  int date, num;
  Node* next;

  Node(int a = 0, Node* b = nullptr) {
    date = a, next = b;
    num = ++cnt;
  }
};

struct CL {
  Node* head;

  CL() : head(nullptr) {}

  void push_front(int x) {
    auto newNode = new Node(x, head);
    head = newNode;
  }

  void insert(int k, int x) {
    Node* now = head;
    while (now->num != k)
      now = now->next;
    auto newNode = new Node(x, now->next);
    now->next = newNode;
  }

  void remove(int k) {
    Node* now = head;
    if (k > 0) {
      while (now->next != nullptr && now->num != k)
        now = now->next;
      auto del = now->next;
      now->next = del->next;
      delete del;
    } else {
      auto del = head;
      head = head->next;
      delete del;
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  auto cl = new CL;
  int m;
  cin >> m;

  while (m--) {
    char op;
    cin >> op;
    if (op == 'H') {
      int x;
      cin >> x;
      cl->push_front(x);
    } else if (op == 'D') {
      int k;
      cin >> k;
      cl->remove(k);
    } else if (op == 'I') {
      int k, x;
      cin >> k >> x;
      cl->insert(k, x);
    }
    // for (auto i = cl->head; i != nullptr; i = i->next)
    //   cout << i->date << ' ';
    // cout << endl;
  }
  for (auto i = cl->head; i != nullptr; i = i->next)
    cout << i->date << ' ';

  return 0;
}