#include <bits/stdc++.h>
using namespace std;
#define List vector
#define Stack stack

template <typename T> struct Node {
  T data;
  Node *next;
};

bool isResonal(List<int> L) {
  Stack<int> buf; // 建立缓存栈
  for (int i = 1, cnt = 0; i <= L.size(); i++) {
    buf.push(i); // 1~n 依此入栈
    while (buf.size() && buf.top() == L[cnt])
      buf.pop(), cnt++; // 若与所给顺序相符，则弹出
  }
  return buf.size() == 0; // 若缓存内元素尽数弹出，则合理
}

template <typename T> void reverse(Node<T> *p) {
  Stack<Node<T> *> stk;
  while (p->next != nullptr) {
    stk.push(p); // 节点指针进栈
    p = p->next; // 指针后移
  }
  while (stk.size()) {
    p->next = stk.top(); // next指向前一节点
    p = p->next;         // 指针前移
    stk.pop();           // 指针使用后立刻出栈
  }
}

template <typename T> void permutation(T *arr, int len, int k = 0) {
  if (k == len - 1) { // 递归出口
    for (int i = 0; i < len; i++)
      cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  //轮流更换第n位和n到total-1位
  for (int i = k; i < len; i++) {
    swap(arr[k], arr[i]);         // 交换
    permutation(arr, len, k + 1); // 递归调用
    swap(arr[k], arr[i]);         // 回溯
  }
}

int FibCnt;
long long Fib(int n) {
  FibCnt++;
  if (n <= 1)
    return n;
  else
    return Fib(n - 1) + Fib(n - 2);
}

long long Fib2(int n) {
  if (n <= 1)
    return n;
  long long a = 0, b = 1, c;
  // for (int i = 2; i <= n; i++)
  while (--n)
    c = a + b, a = b, b = c;
  return c;
}

constexpr int N = 1e5 + 5;
long long dp[1234]{0, 1};
void init() { // dp数组初始化
  dp[0] = 0, dp[1] = 1;
  for (int i = 2; i < N; i++)
    dp[i] = -1;
}
long long Fib1(int n) {
  FibCnt++;
  // cout << "Fib() calls, n = " << n << endl;
  if (dp[n] >= 0)
    return dp[n];
  else
    return dp[n] = Fib1(n - 1) + Fib1(n - 2);
}

int main() {
  int n;
  long long v = 0, cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    FibCnt = 0;
    // init();
    // cout << "i = " << i << ": " << (v = Fib(i)) << "\t" << FibCnt << "\t"
    //      << (cnt += v) << endl;
    cout << Fib2(i) << endl;
  }
  return 0;
}

// Node* reverse(Node* head) {
//   Node *prev = nullptr, *cur = head;
//   while (cur) {
//     Node* next = cur->next;
//     cur->next = prev;
//     prev = cur, cur = next;
//   }
//   return prev;
// }

// template <class T>
// bool SeqList<T>::Insert(int i, T& x) {
//   //将新元素x插入到表中第 i(0≤i≤last+1)个表项之后
//   if (last == maxSize - 1)
//     return false;  //表满
//   if (i < 0 || i > last + 1)
//     return false;                  //参数i不合理
//   for (int j = last; j >= i; j--)  //依次后移
//     data[j + 1] = data[j];
//   data[i] = x;  //插入(第 i 表项在data[i-1]处)
//   last++;
//   return true;  //插入成功
// }

// template <class T>
// bool SeqList<T>::Reserve(int r) {
//   if (r < last)
//     return false;
//   T* newSpace = new T[r];
//   for (int i = first; i != last; i++)
//     newSpace[i] = data[i];
//   delete[] data;
//   data = newSpace, maxSize = r;
//   return true;
// }

// template <class T>
// bool SeqList<T>::Insert(int i, T& x) {
//   //将新元素x插入到表中第i (0≤i≤last+1) 个表项之后
//   if (last == maxSize - 1)
//     if (!Reserve(last << 1))
//       return false;
//   if (i < 0 || i > last + 1)
//     return false;                  //参数i不合理
//   for (int j = last; j >= i; j--)  //依次后移
//     data[j + 1] = data[j];
//   data[i] = x;  //插入(第 i 表项在data[i-1]处)
//   last++;
//   return true;  //插入成功
// }

// template <typename T>
// void SeqList<T>::remove(const T& x) {  //删除值等于x的所有元素
//   int cnt = 0;
//   for (int i = 0; i < size; i++) {
//     if (data[i] == x)
//       cnt++, size--;  //当前元素为x时k增1
//     else
//       data[i - cnt] = data[i];  //当前元素不为x时将其前移k个位置
//   }
// }

int DFS_PostOrder(BinTree *T) {
  if (!T)
    return 0; //树空，高度为0
  Stack<BinNode *> stk;
  BinTree *p = T, *r = nullptr; // r为后序遍历时的辅助指针
  int num = 0, max = 0; // num用来跟随程序实时记录层数，max用来记录最大值
  while (p || !stk.empty()) { //以下为后序遍历略作修改
    while (p) {               //该结点入栈并搜索其左孩子
      stk.push(p);
      num++;
      if (num > max)
        max = num;
      p = p->lChild;
    }
    p = stk.top();
    if (p->rChild && p->rChild != r)
      p = p->rChild; //如果右孩子存在并还没访问，则访问
    else {
      p = stk.pop();
      num--; //出栈则层数减1
      r = p; // r指向上一个访问节点
      p = nullptr;
    }
  }

  ruturn max; //返回最大高度
}

template <class T> struct stkNode {
  int height = -1;
  BinNode<T> *ptr;                                  //树结点指针
  enum tag { L, R };                                //退栈标记
  stkNode(BinNode<T> *N = NULL) : ptr(N), tag(L) {} //构造函数
};

template <class T> void BinTree<T>::getHeight() {
  Stack<stkNode<T>> S;
  stkNode<T> w;
  BinNode<T> *p = root; // p是遍历指针
  int height = 0;
  do {
    while (p) {
      w.ptr = p, w.tag = L;
      S.push(w);
      p = p->lChild;
      height = std::max(height, S.size());
    }
    int continue1 = 1; //继续循环标记, 用于R
    while (continue1 && !S.empty()) {
      w = S.pop();
      p = w.ptr;
      if (w.tag == L) { //判断栈顶的tag标记
        w.tag = R;
        S.push(w);
        continue1 = 0;
        p = p->rChild;
      }
    }
  } while (!S.empty()); //继续遍历其他结点
  return height;
}
