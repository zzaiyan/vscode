#include <bits/stdc++.h>
using namespace std;

int vNum;
int *inDegree;
queue<int> que;
queue<int> ans;

bool TopoSort(string G) {
  int cnt = 0;
  int inDegree[G.vexNum];
  for (int i = 1; i <= G.vexNum; i++) { //将整个图中的入度为零的节点放入队列
    if (inDegree[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    int now = que.front();
    ans.push(now), que.pop();
    for (int i = 0; i < G[now].size(); i++) {
      int v = G[now][i];
      inDegree[v]--;
      if (inDegree[v] == 0) { // 再次将入度为零的点放入队列
        que.push(v);
      }
    }
  }
  if (cnt == G.vexNum)
    return true; //排序成功
  else
    return false; //有回路，排序失败
}

int main() {
  cin >> vNum;
  inDegree = new int[vNum + 1];
  for (int i = 0; i < vNum; i++) {
    int in;
    cin >> in;
    inDegree[i] = in;
  }
}

bool 拓扑排序(string G) {
  int m = 0;     // m 表示输出顶点的总数
  list<int> ans; // 拓扑排序结果
  计算顶点入度数组 inDegree[];
  将所有入度为 0 的顶点加入队列 Q;
  while (队列 Q 非空) {
    弹出队顶，得到顶点 v 并存入 ans 数组;
    m++;
    对顶点 v 的所有邻接点 : 入度减 1, 若其入度为 0 则入队列 Q;
  }
  if (m < G.vexNum)
    return false; //有回路，排序失败
  else
    return true; //无回路，排序成功
}

bool Kahn() {
  int[] inDegree = new int[v]; //每个顶点的入度
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      int w = adj[i].get(j);
      inDegree[w]++; //统计每个顶点的入度
    }
  }
  LinkedList<Integer> queue = new LinkedList<>(); //创建一个队列
  for (int i = 0; i < v; i++) {
    if (inDegree[i] == 0)
      queue.add(i); //将入度为0的入队
  }
  while (!queue.isEmpty()) {
    int i = queue.remove(); //依次出队
    System.out.print("->" + i);
    for (int j = 0; j < adj[i].size(); j++) {
      int k = adj[i].get(j);
      inDegree[k]--; //将这个顶点所指向的所有顶点入度减1
      if (inDegree[k] == 0)
        queue.add(k); //若减一后入度为0则入队
    }
  }
}
