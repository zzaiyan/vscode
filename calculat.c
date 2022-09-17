#include <stdio.h>
int main() {
  char in, c = '+';
  int v = 0, rst = 0;
  while (in = getchar())
    if ((in < '0') || (in > '9')) {
      if (c == '+')
        rst += v;
      else if (c == '-')
        rst -= v;
      else if (c == '*')
        rst *= v;
      else if (c == '/')
        rst /= v;
      if (in == '\n')
        return !printf("%d\n", rst);
      c = in;
      v = 0;
    } else
      v = v * 10 + (in - '0');
}