#include <bits/stdc++.h>
using namespace std;

//节点及构造函数
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

//插入函数：若传入空链表，则指向新节点
ListNode* insertNode(ListNode* front, int data) {
  ListNode* newNode = new ListNode(data);
  if (front == nullptr)
    return newNode;
  newNode->next = front->next;
  front->next = newNode;
  return newNode;
}

ListNode* pushFront(ListNode* head, int data) {
  if (head == nullptr)
    return head;
  ListNode* newNode = new ListNode(data);
  newNode->next = head;
  return newNode;
}

//在链表尾部新增节点
ListNode* pushBack(ListNode* head, int data) {
  ListNode* newNode = new ListNode(data);
  if (head == nullptr)
    return newNode;
  while (head->next != nullptr)
    head = head->next;
  head->next = newNode;
  return newNode;
}

//按数据删除节点
ListNode* deleteData(ListNode* head, int data) {
  ListNode* p = head;
  //判断是否为空指针
  if (p == nullptr)
    return head;
  //判断是否为头节点
  if (p->val == data) {
    head = p->next;
    delete p;
    return head;
  } else {
    //定位至欲删除的前一节点
    while (p->next != nullptr && p->next->val != data)
      p = p->next;
    //如果没有找到该数值
    if (p->next == nullptr)
      return head;
    //短路并删除节点
    auto del = p->next;
    p->next = p->next->next;
    delete del;
    return head;
  }
}

//删除下一个节点
ListNode* deleteNext(ListNode* front) {
  if (front == nullptr)
    return front;
  auto del = front->next;
  front->next = front->next->next;
  delete del;
  return front;
}

//获取长度
int getLenth(ListNode* head) {
  int cnt = 0;
  while (head != nullptr) {
    head = head->next;
    ++cnt;
  }
  return cnt;
}

void printList(ListNode* m) {
  while (m != nullptr) {
    cout << m->val << ' ';
    m = m->next;
  }
}

int main() {
  int num;
  cin >> num;
  //创建链表
  ListNode* head = new ListNode(num);
  ListNode* tail = head;

  //利用插入函数延长链表
  while (cin >> num && num != -1)
    tail = insertNode(tail, num);

  //利用尾插函数延长链表
  // while(cin>>num&&num!=-1)tail=pushBack(head,num);

  //从head开始遍历链表，输出val值，直至链表尾
  cout << "输出链表：";
  printList(head);
  cout << endl;

  // cout<<"请输入删除的数值：";
  // cin>>num;
  // //调用删除函数删除指定数值节点
  // head=deleteData(head,num);
  head->next = deleteNext(head->next);

  cout << "输出链表：";
  printList(head);
  cout << endl;

  return 0;
}
