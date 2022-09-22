//#include<bits/stdc++.h>
//#include<stdio.h>
//#include  <stdbool.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
long Fibnacci(long n) {
  int sum = 0;
  queue<long> q;
  q.push(0), q.push(1);
  while (n--) {
    sum = q.front();
    q.pop();
    q.push(sum + q.front());
  }
  return q.front();
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cout << Fibnacci(i) << endl;
}