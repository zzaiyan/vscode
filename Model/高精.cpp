#include <bits/stdc++.h>
using namespace std;

string multy(string &str1, string &str2) {
  size_t size1 = str1.size(), size2 = str2.size();

  if (str1 == "0" || str2 == "0") return "0";
  if (size1 + size2 < 9)
    return to_string(atoi(str1.c_str()) *
                     atoi(str2.c_str()));  //对int范围内进行优化

  size_t maxSize = max(size1, size2) + 5;
  int *arr1 = new int[maxSize]{0};
  int *arr2 = new int[maxSize]{0};
  int *ans = new int[2 * maxSize]{0};
  for (size_t i = 0; i < size1; i++) arr1[i] = str1[size1 - 1 - i] - '0';
  for (size_t i = 0; i < size2; i++) arr2[i] = str2[size2 - 1 - i] - '0';

  for (size_t i = 0; i < size1; i++)
    for (size_t j = 0; j < size2; j++) ans[i + j] += arr1[i] * arr2[j];

  for (size_t i = 0; i < 2 * maxSize - 5; i++) {
    if (ans[i] >= 10) {
      ans[i + 1] += ans[i] / 10;
      ans[i] %= 10;
    }
  }

  int p;
  string ret = "";
  for (p = 2 * maxSize - 5; !ans[p]; p--)
    ;
  for (; p >= 0; p--) ret.push_back(char(ans[p] + '0'));

  delete[] arr1;
  delete[] arr2;
  delete[] ans;
  return ret;
}

string add(string &str1, string &str2) {
  size_t size1 = str1.size(), size2 = str2.size();
  size_t maxSize = max(size1, size2) + 5;

  if (maxSize - 5 < 9)
    return to_string(atoi(str1.c_str()) +
                     atoi(str2.c_str()));  //对int范围内进行优化

  int *arr1 = new int[maxSize]{0};
  int *arr2 = new int[maxSize]{0};
  int *ans = new int[maxSize]{0};
  for (size_t i = 0; i < size1; i++) arr1[i] = str1[size1 - 1 - i] - '0';
  for (size_t i = 0; i < size2; i++) arr2[i] = str2[size2 - 1 - i] - '0';

  for (size_t i = 0; i < maxSize; i++) ans[i] += arr1[i] + arr2[i];

  for (size_t i = 0; i < maxSize; i++) {
    if (ans[i] >= 10) {
      ans[i + 1] += ans[i] / 10;
      ans[i] %= 10;
    }
  }

  int p;
  string ret = "";
  for (p = maxSize - 1; !ans[p]; p--)
    ;
  for (; p >= 0; p--) ret.push_back(char(ans[p] + '0'));

  delete[] arr1;
  delete[] arr2;
  delete[] ans;
  return ret;
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << multy(a, b) << endl;
  cout << add(a, b) << endl;
}