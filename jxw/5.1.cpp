#include <bits/stdc++.h>
using namespace std;
using SeqList = vector<int>;

void reverse(SeqList& ele) {
  for (int i = 0, j = ele.size() - 1; i < j; i++, j--)
    swap(ele[i], ele[j]);
}

int main() {
  SeqList ele;
  int n;  // 数据规模
  cin >> n;

  while (n--)  // 读入数据
    ele.push_back(rand() % 100);

  cout << "原始数据 ";
  for (auto i : ele)
    cout << i << ' ';

  reverse(ele);

  cout << "\n 反转后  ";
  for (auto i : ele)
    cout << i << ' ';
  return !(cout << '\n');
}