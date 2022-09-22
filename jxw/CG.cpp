//#include<bits/stdc++.h>
//#include<stdio.h>
//#include  <stdbool.h>
#include <iostream>
using namespace std;

//递归算法,引用times1，用于记录递归算法，fib1调用的次数
long Fib1(long n, int& times1) {
  times1++;
  if (n <= 1)
    return n;
  else
    return Fib1(n - 1, times1) + Fib1(n - 2, times1);
}

//非递归算法,引用times2，用于记录非递归算法，fib2调用的次数
long Fib2(long n, int& times2) {
  times2++;
  if (n <= 1)
    return n;
  long long a = 0, b = 1, c;
  for (int i = 2; i <= n; i++)
    c = a + b, a = b, b = c;
  return c;
}
int main() {
  //对比递归和非递归Fib的调用次数
  int times1 = 0, times2 = 0;
  int n = 3;
  Fib1(n, times1);
  Fib2(n, times2);
  cout << "递归算法的次数" << times1 << endl;
  cout << "非递归算法的次数" << times2 << endl;
  times1 = 0, times2 = 0;
  n = 10;
  Fib1(n, times1);
  Fib2(n, times2);
  cout << "递归算法的次数" << times1 << endl;
  cout << "非递归算法的次数" << times2 << endl;
  return 0;
}