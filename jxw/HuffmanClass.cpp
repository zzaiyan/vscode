#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

constexpr int MAXBIT = 10;
constexpr int MAXVALUE = 10000;
constexpr int MAXLEAF = 10;
constexpr int MAXNODE = MAXLEAF * 2 - 1;

using namespace std;

struct HCodeType {
  int bit[MAXBIT];
  int start;
}; /* 编码结构体 */

struct HNodeType {
  int weight = 0, parent = -1, lChild = -1, rChild = -1;
  char value = '@';
}; /* 结点结构体 */

class HuffmanTree {
  HNodeType HuffNode[MAXNODE];
  HCodeType HuffCode[MAXLEAF];
  int n = 10;  // 字典长度
  string buf;

 public:
  HuffmanTree() { cout << sizeof(HuffNode) << endl; }

  void coding(string str) {
    int i, j, m1, m2, x1, x2;
    // 首先统计数字出现的次数
    int charCnt[10]{0};
    for (auto ch : str) {
      charCnt[ch - '0']++;
    }
    for (int i = 0; i < 10; i++) {
      HuffNode[i].value = i + '0';
      HuffNode[i].weight = charCnt[i];
    }
    for (i = 0; i < n - 1; i++) {
      m1 = m2 = MAXVALUE; /* m1、m2中存放两个无父结点且结点权值最小的两个结点 */
      x1 = x2 = 0;
      /* 找出所有结点中权值最小、无父结点的两个结点，并合并之为一颗二叉树 */
      for (j = 0; j < n + i; j++) {
        if (HuffNode[j].weight < m1 && HuffNode[j].parent == -1) {
          m2 = m1;
          x2 = x1;
          m1 = HuffNode[j].weight;
          x1 = j;
        } else if (HuffNode[j].weight < m2 && HuffNode[j].parent == -1) {
          m2 = HuffNode[j].weight;
          x2 = j;
        }
      } /* end for */
      /* 设置找到的两个子结点 x1、x2 的父结点信息 */
      HuffNode[x1].parent = n + i;
      HuffNode[x2].parent = n + i;
      HuffNode[n + i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
      HuffNode[n + i].lChild = x1;
      HuffNode[n + i].rChild = x2;
    }
    HCodeType cd;
    int c, p;
    for (i = 0; i < n; i++) {
      cd.start = n - 1;
      c = i;
      p = HuffNode[c].parent;
      while (p != -1) /* 父结点存在 */
      {
        if (HuffNode[p].lChild == c)
          cd.bit[cd.start] = 0;
        else
          cd.bit[cd.start] = 1;
        cd.start--; /* 求编码的低一位 */
        c = p;
        p = HuffNode[c].parent; /* 设置下一循环条件 */
      }                         /* end while */

      /* 保存求出的每个叶结点的哈夫曼编码和编码的起始位 */
      for (j = cd.start + 1; j < n; j++) {
        HuffCode[i].bit[j] = cd.bit[j];
      }
      HuffCode[i].start = cd.start;
    } /* end for */
  }

  string getDic() {
    string ret;
    for (int i = 0; i < MAXNODE; i++) {
    }
    return string{};
  }

  void importDic(string dic) {}

  void decoding(string str) {
    int i, tmp = 0, code[1024];
    int Num = MAXLEAF;
    int m = MAXNODE;

    char* nump;
    char num[1024];
    for (i = 0; i < str.size(); i++) {
      if (str[i] == '0')
        num[i] = 0;
      else
        num[i] = 1;
    }
    i = 0;
    nump = &num[0];

    while (i < str.size()) {
      tmp = m - 1;
      while ((HuffNode[tmp].lChild != -1) && (HuffNode[tmp].rChild != -1)) {
        if (num[i] == 0) {
          tmp = HuffNode[tmp].lChild;
        } else
          tmp = HuffNode[tmp].rChild;
        i++;
      }
      printf("%c", HuffNode[tmp].value);
    }  // 13875765918
  }

  void printMatrix() {
    for (int i = 0; i < MAXNODE; i++) {
      // for (int j = 0; j < 4; j++)
      printf("%c  %d  %d  %d  %d \n", HuffNode[i].value, HuffNode[i].weight,
             HuffNode[i].parent, HuffNode[i].lChild, HuffNode[i].rChild);
    }
  }
};

int main() {
  string str{"52771234567890"};
  HuffmanTree huf;
  huf.coding(str);
  huf.decoding("1000110000");
  cout << endl;
  string sss("914678347984318880354578107745501987346623601575895435888739");
  cout << sss.size() << endl;
  huf.printMatrix();

  return 0;
}