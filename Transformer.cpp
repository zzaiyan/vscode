#include <bits/stdc++.h>
using namespace std;
string formate(long double origin, int src, int tar) {
  long double a = 0;
  int dot = 0;
  string num = to_string(origin);
  // cout<<"num="<<num<<endl;
  for (char i : num) {
    if (i == '.')
      break;
    else
      dot++;
  }
  long double rate = pow(src, dot - 1);
  for (char i : num) {
    if (i != '.') {
      // cout<<"i="<<i<<" rate="<<rate<<endl;
      if (i != '0')
        a += (i - '0') * rate;
      rate /= src;
    }
  }
  // cout<<"a="<<a<<endl;
  static char str[100] = {
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/"};
  string result = ""; // ⽤于储存结果字符串
  try {
    if (tar <= 1 || tar > 64)
      throw "进制错误"; //由于最⼤⽀持64进制，并且排除0等错误进制
    int c = 0;          //⽤于储存余数
    int n = (int)a;
    do {
      c = n % tar;
      n = n / tar;
      result = str[c] + result;
    } while (n);
    if (!(a - (int)a))
      return result;
    result = result + '.';
    int clock = 0; //防⽌⽆限循环
    do {
      if (clock >= 10)
        return result;
      a = a - (int)a;
      a = a * tar;
      n = (int)(a);
      result += str[n];
      clock++;
    } while (a);
    return result.substr(0, result.length() - 1); //去除多余的⼀位
  } catch (...) {
    return "进制错误";
  }
}

int main() {
  long double num;
  int s, t;
  cout << "请输入要转换的数：\n";
  cin >> num;
  cout << "请输入原始进制：\n";
  cin >> s;
  cout << "请输入目标进制：\n";
  cin >> t;
  string result = formate(num, s, t);
  cout << "转换结果为：" << result << endl;
  return 0;
}