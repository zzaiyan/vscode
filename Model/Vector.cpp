#include <bits/stdc++.h>
using namespace std;

template <typename T> class MyVector {
  T *marr;
  size_t msize;

public:
  MyVector() : marr(nullptr), msize(0) {}
  MyVector(T *a, T *b) {
    marr = new T[msize = b - a];
    for (int i = 0; i < msize; ++i)
      marr[i] = *(a + i);
  }
  MyVector(const MyVector &A) {
    marr = new T[msize = A.msize];
    for (int i = 0; i < msize; ++i)
      marr[i] = A.marr[i];
  }
  ~MyVector() { delete[] marr; }
  T *begin() { return marr; }
  T *end() { return marr + msize; }
  size_t size() { return msize; }
  MyVector &operator=(const MyVector &A) {
    delete[] marr;
    marr = new T[msize = A.msize];
    for (int i = 0; i < msize; ++i)
      marr[i] = A.marr[i];
    return *this;
  }
  T &operator[](int n) { return marr[n > 0 ? n : 0]; }
  void push_back(T t) {
    auto old = marr;
    marr = new T[msize + 1];
    for (int i = 0; i < msize; ++i)
      marr[i] = old[i];
    marr[msize++] = t;
    delete[] old;
  }
  void pop_back() { --msize; }
  void insert(int pos, T t) {
    auto old = marr;
    marr = new T[++msize];
    for (int i = 0; i < pos; ++i)
      marr[i] = old[i];
    marr[pos] = t;
    for (int i = pos + 1; i < msize; ++i)
      marr[i] = old[i - 1];
    delete[] old;
  }
  void erase(int pos) {
    for (int i = pos; i + 1 < msize; ++i)
      marr[i] = marr[i + 1];
    --msize;
  }
};

int main() {
  MyVector<int> vec;
  int x;
  //尾插元素
  while (cin >> x && x != -1)
    vec.push_back(x);
  //迭代器遍历
  for (auto p = vec.begin(); p != vec.end(); ++p)
    cout << *p << ' ';
  putchar('\n');

  //插入函数
  vec.insert(1, -1);
  //迭代器遍历
  for (auto p = vec.begin(); p != vec.end(); ++p)
    cout << *p << ' ';
  putchar('\n');

  //赋值函数
  auto nvec = vec;
  //迭代器遍历
  for (auto p = nvec.begin(); p != nvec.end(); ++p)
    cout << *p << ' ';
  putchar('\n');

  //区间构造函数
  int arr[] = {1, 2, 3, 4, 5};
  MyVector<int> arrvec(arr, arr + 5);
  //迭代器遍历
  for (auto p = arrvec.begin(); p != arrvec.end(); ++p)
    cout << *p << ' ';
  putchar('\n');

  return 0;
}