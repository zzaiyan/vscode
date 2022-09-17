#include <bits/stdc++.h>
using namespace std;

//节点及构造函数
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x, ListNode* p = nullptr) : val(x), next(p) {}
};

//插入函数：在给定节点后插入新节点，若传入空指针，则指向新节点
ListNode* insertNode(ListNode* front, int data) {
  ListNode* newNode = new ListNode(data);
  if (front == nullptr)
    return newNode;
  newNode->next = front->next;
  front->next = newNode;
  return newNode;
}

void printList(ListNode* m) {
  while (m != nullptr) {
    cout << m->val << ' ';
    m = m->next;
  }
}

int main() {
  int num;
  //创建链表
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  ListNode* tail = head->next;

  cout << "输出链表：";
  printList(head);
  cout << endl;

  //利用插入函数延长链表
  while (cin >> num && num != -1)
    insertNode(head, num);

  cout << "输出链表：";
  printList(head);
  cout << endl;

  return 0;
}