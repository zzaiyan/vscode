#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

void insertAfter(Node *pos, int e) {
  auto newNode = new Node{e, pos->next};
  pos->next = newNode;
}

// remove by Rank
void remove(Node *head, int r) {
  while (r--)
    head = head->next;
  auto del = head->next;
  head->next = del->next;
  delete del;
}

void show(Node *head) {
  for (auto p = head->next; p != head; p = p->next)
    cout << p->data << ' ';
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  // 创造附加头节点
  auto head = new Node{0, 0};
  // 设置head为循环链表
  head->next = head;
  // 在头部插入元素
  for (int i = 0; i < n; i++)
    insertAfter(head, i + 1);
  // 测试
  show(head);
  show(head->next);
  remove(head, 0);
  show(head);
  remove(head, 3);
  show(head);
  return 0;
}

template <class T> bool SeqList<T>::Insert(int i, T &x) {
  //将新元素x插入到表中第 i(0≤i≤last+1)个表项之后
  if (last == maxSize - 1)
    return false; //表满
  if (i < 0 || i > last + 1)
    return false;                 //参数i不合理
  for (int j = last; j >= i; j--) //依次后移
    data[j + 1] = data[j];
  data[i] = x; //插入(第 i 表项在data[i-1]处)
  last++;
  return true; //插入成功
}

template <class T> bool reserve(int s) {
  if (s <= _size)
    return false;
  T *newSpace = new T[s];
  for (int i = 0; i < _size; i++)
    newSpace[i] = _data[i];
  delete[] _data;
  _data = newSpace;
  return true;
}

template <class T> int SeqList<T>::romove(const T &e) {
  int newSize = 0, ret;
  T newData = new T[last];
  for (int i = 0; i < last; i++)
    if (data[i] != e)
      newData[newSize++] = data[i];
  delete data;
  data = newData;                       // 更新 data 指针
  ret = last - newSize, last = newSize; // 更新 size
  return ret;                           // 返回删除的元素个数
}

template <class T> bool List<T>::Insert(int i, T &x) {
  //将新元素 x 插入在链表中第 i 个结点之后。
  LinkNode<T> *current = Locate(i);
  if (current == NULL)
    return false;                            //无插入位置
  LinkNode<T> *newNode = new LinkNode<T>(x); //创建新结点
  newNode->link = current->link;             //链接在current之后
  current->link = newNode;
  return true; //插入成功
}

template <class T> bool List<T>::Insert(ListNode<T> *p, T &x) {
  LinkNode<T> *newNode = new LinkNode<T>{x, p->link}; //创建新结点
  if (newNode != nullptr) {
    p->link = newNode;
    return true; //插入成功}
  }
  return false;
}

template <class T> int List<T>::Insert(T &e, T &x) {
  int cnt = 0;
  for (auto p = head; p != nullptr; p = p->link)
    if (p->data == e)
      Insert(p, x), cnt++;
  return cnt;
}

template <class T> void List<T>::Remove(ListNode<T> *p) {
  auto del = p->link;
  p->link = del->link;
  delete del;
}

template <class T> int List<T>::Remove(T &e) {
  int cnt = 0; // 记录插入元素个数
  for (auto p = head; p != nullptr; p = p->link)
    if (p->data == e)
      Remove(p), cnt++; // 若值符合要求，则插入
  return cnt;
}

template <class T> ListNode<T> *List<T>::getPre(ListNode<T> *p) {
  for (auto pre = head; pre != nullptr; pre = pre->link)
    if (pre->link == p)
      return pre;
  return nullptr;
}