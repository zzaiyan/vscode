#include <bits/stdc++.h>
using namespace std;

struct MyInt {
  int val;
  bool operator<(const MyInt& A) {
    if (val < A.val) {
      cout << val << " < " << A.val << "\n";
    } else
      cout << val << " >= " << A.val << "\n";
    return val < A.val;
  }
  const MyInt& operator=(const MyInt& A) {
    val = A.val;
    cout << "operator= calls. val = " << val << " .\n";
    return *this;
  }
  MyInt operator-(const MyInt& A) { return MyInt{val - A.val}; }
};

void show(const list<MyInt>& L) {
  for (auto i : L)
    cout << i.val << ' ';
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  list<MyInt> L;

  while (n--)
    L.push_back(MyInt{rand() % 100 + 1});

  show(L);

  auto p = L.begin();

  cout << "L.begin() = " << (*p).val << endl;

  L.sort();  // stl自带排序

  cout << "L.begin() = " << (*p).val << endl;

  show(L);
}