#include <bits/stdc++.h>
using namespace std;

int bfCnt = 0, kmpCnt = 0;

int bf(const string& str, const string& pat) {
  for (int i = 0; i < str.size(); i++) {
    int k = i, j = 0;
    while (k < str.size() && j < pat.size()) {
      if (str[k] != pat[j])
        break;
      k++, j++, bfCnt++;
    }
    bfCnt++;  // 记录退出前的一次比较
    if (j == pat.size())
      return i;
  }
  return -1;
}

int kmp(const string& str, const string& pat) {
  int* ne = new int[pat.size() + 2]{-1, 0};

  for (int i = 2; i < pat.size() + 1; i++) {
    int j = ne[i - 1];
    while (j && pat[i - 1] != pat[j])
      j = ne[j];
    if (pat[i - 1] == pat[j])
      j++;
    ne[i] = j;
  }

  // cout << "\nne: ";
  // for (int i = 0; i < pat.size(); i++)
  //   cout << ne[i] << ' ';
  // cout << "\n";

  for (int i = 0, j = 0; i < str.size(); i++) {
    kmpCnt++;
    while (j && str[i] != pat[j])
      j = ne[j];
    if (str[i] == pat[j])
      j++;
    if (j == pat.size()) {
      // cout << "匹配成功: " << i - j + 1 << "\n";
      return (i - j + 1);
    }
  }
  delete[] ne;
  return -1;  // 匹配失败
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string str, pat;
  cin >> str >> pat;

  cout << bf(str, pat) << endl << bfCnt << endl;
  cout << kmp(str, pat) << endl << kmpCnt << endl;

  return 0;
}