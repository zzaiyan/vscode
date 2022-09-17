#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1e6 + 10, N = 1e5 + 10;

void kmp(int str_size, char* str, int pat_size, char* pat) {
  int* ne = new int[pat_size + 5];

  for (int i = 2, j = 0; i <= pat_size; i++) {
    while (j > 0 && pat[i] != pat[j + 1])
      j = ne[j];
    pat[i] == pat[j + 1] && j++;
    ne[i] = j;
  }

  cout << "\nne: ";
  for (int i = 1; i <= pat_size; i++)
    cout << ne[i] << ' ';
  cout << "\n";

  for (int i = 1, j = 0; i <= str_size; i++) {
    while (j > 0 && str[i] != pat[j + 1])
      j = ne[j];
    str[i] == pat[j + 1] && j++;
    if (j == pat_size)
      cout << "匹配成功: " << i - pat_size + 1 << endl;
  }

  delete[] ne;
}

void kmp(const string& str, const string& pat) {
  int* ne = new int[pat.size() + 5];

  for (int i = 1, j = -1; i < pat.size(); i++) {
    while (j >= 0 && pat[i] != pat[j + 1])
      j = ne[j];
    pat[i] == pat[j + 1] && j++;
    ne[i] = j;
  }

  cout << "\nne: ";
  for (int i = 0; i < pat.size(); i++)
    cout << ne[i] << ' ';
  cout << "\n";

  for (int i = 0, j = -1; i < str.size(); i++) {
    while (j >= 0 && str[i] != pat[j + 1])
      j = ne[j];
    str[i] == pat[j + 1] && j++;
    if (j == pat.size())
      cout << "匹配成功: " << i - pat.size() + 1 << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  // char pat[N], str[M];
  // int str_size, pat_size;
  // cin >> str_size >> str + 1 >> pat_size >> pat + 1;
  // kmp(str_size, str, pat_size, pat);
  string str, pat;
  cin >> str >> pat;
  kmp(str, pat);
  return 0;
}