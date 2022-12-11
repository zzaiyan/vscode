#include <iostream>
#include <list>
#include <queue>
#include <stack>
using std::list;
using std::queue;
using std::stack;

template <class T> class AdjGraph {
public:
  AdjGraph(size_t capacity = 20);
  ~AdjGraph();

  class Vertex { //顶点
  public:
    Vertex(T v) : bVisited(0) { val = v; }
    friend class AdjGraph<T>;

  private:
    T val;
    bool bVisited;
  };

public:
  void addVertex(const T &);        //增加顶点
  void addEdge(int start, int end); //增加边
  void printVertice() const;        //打印所有顶点
  void printAdjTable() const;       //打印邻接表

  void BFS(void (*f)(T t));
  void DFS(void (*f)(T t));

private:
  size_t _size;     //顶点个数
  size_t _capacity; //最多可容纳顶点数

  Vertex **_vArray;  //顶点列表
  list<int> *_pList; //邻接表
};

template <class T>
inline AdjGraph<T>::AdjGraph(size_t c) : _size(0), _capacity(c) {
  _vArray = new Vertex *[c];
  _pList = new list<int>[c];
}

template <class T> inline AdjGraph<T>::~AdjGraph() {
  delete[] _vArray;
  delete[] _pList;
}

template <class T> inline void AdjGraph<T>::addVertex(const T &item) {
  if (_size == _capacity)
    throw "超出容量";
  _vArray[_size++] = new Vertex(item);
}

template <class T> inline void AdjGraph<T>::addEdge(int start, int end) {
  _pList[start].push_back(end);
}

template <class T> inline void AdjGraph<T>::printVertice() const {
  std::cout << "顶点个数为 " << _size << " 个:"
            << "\n";
  for (size_t i = 0; i < _size; i++) {
    std::cout << _vArray[i]->val << " ";
  }
  std::cout << "\n";
}

template <class T> inline void AdjGraph<T>::printAdjTable() const {
  for (size_t i = 0; i < _size; i++) {
    std::cout << _vArray[i]->val;
    for (auto iter = _pList[i].begin(); iter != _pList[i].end(); ++iter)
      std::cout << " -> " << *iter;
    std::cout << "\n";
  }
}

template <class T> inline void AdjGraph<T>::BFS(void (*f)(T t)) {
  if (_size == 0)
    return;

  queue<int> q;
  q.push(0);
  _vArray[0]->bVisited = true; //标记已访问

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    // std::cout << " -> " << _vArray[cur]->val;
    f(_vArray[cur]->val); //访问结点

    //遍历该节点的邻接表,把未访问的连接结点加入队列
    for (auto it = _pList[cur].begin(); it != _pList[cur].end(); it++) {
      if (!_vArray[*it]->bVisited) {
        q.push(*it);
        _vArray[*it]->bVisited = true; //标记已访问
      }
    }
  }

  //恢复未访问状态
  for (size_t i = 0; i < _size; i++) {
    _vArray[i]->bVisited = false;
  }
}

template <class T> inline void AdjGraph<T>::DFS(void (*f)(T t)) {
  if (_size == 0)
    return;

  stack<int> st;
  st.push(0);
  _vArray[0]->bVisited = true; //标记已访问

  while (!st.empty()) {
    int cur = st.top();
    st.pop();
    // std::cout << " -> " << _vArray[cur]->val;
    f(_vArray[cur]->val); //访问结点

    for (auto it = _pList[cur].begin(); it != _pList[cur].end(); it++) {
      if (!_vArray[*it]->bVisited) {
        st.push(*it);
        _vArray[*it]->bVisited = true; //标记已访问
      }
    }
  }

  //恢复未访问状态
  for (size_t i = 0; i < _size; i++) {
    _vArray[i]->bVisited = false;
  }
}

int main() {
  AdjGraph<char> g;
  g.addVertex('A'); // 0
  g.addVertex('B'); // 1
  g.addVertex('C'); // 2
  g.addVertex('D'); // 3
  g.addVertex('E'); // 4

  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(1, 0);
  g.addEdge(1, 4);
  g.addEdge(2, 4);
  g.addEdge(3, 0);
  g.addEdge(3, 4);
  g.addEdge(4, 1);
  g.addEdge(4, 2);
  g.addEdge(4, 3);

  g.printVertice();
  g.printAdjTable();

  auto visit = [](char x) { printf("%c ", x); };

  g.BFS(visit);
  puts("");

  g.DFS(visit);
  puts("");

  return 0;
}