#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

map<int, int> level2node;
int dfs(int node, int level, map<int,vector<int>> &edges, set<int> &visited) {
  visited.insert(node);
  for (auto nex_node : edges[node]) {
    if (visited.count(nex_node) == 1) continue;
    level = dfs(nex_node, level, edges, visited);
  }
  if (level2node.count(level) == 1) {
    cout << "errorr" << endl;
  }
  level2node[level] = node;
  return level+1;
}

map<int,vector<int>> reverseEdges(map<int,vector<int>> &edges) {
  map<int,vector<int>> revEdges;
  for (auto each_edge : edges) {
    for (auto each_to : each_edge.second) {
      revEdges[each_to].push_back(each_edge.first);
    }
  }
  return revEdges;
}

void dfs2(int node, map<int,vector<int>> &edges, vector<int> &tmp_scc, set<int> &visited) {
  visited.insert(node);
  tmp_scc.push_back(node);
  for (auto nex_node : edges[node]) {
    if (visited.count(nex_node) == 1) continue;
    dfs2(nex_node, edges, tmp_scc, visited);
  }
  return ;
}

vector<vector<int>> tarjan(int n, map<int,vector<int>> &edges) {
  // assign numbers
  set<int> visited;
  int level = 1;
  for (int node=1;node<=n;node++) {
    if (visited.count(node) == 1) continue;
    level = dfs(node, level, edges, visited);
  }

  map<int,vector<int>> reversed = reverseEdges(edges);

  set<int> visited2;
  vector<vector<int>> sccs;
  for (int node_level=n;node_level>=1;node_level--) {
    int start_node = level2node[node_level];
    // cout << "start_node " << start_node << endl;
    if (visited2.count(start_node)==1) continue;
    // cout << "executing.. " << endl;
    vector<int> tmp_scc;
    dfs2(start_node, reversed, tmp_scc, visited2);
    sccs.push_back(tmp_scc);
  }
  return sccs;
}

void print(vector<vector<int>> v) {
  for (int i=0;i<v.size();i++) {
    for (int j=0;j<v[i].size();j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

void printEdge(map<int,vector<int>> edges) {
  for (auto each_edge : edges) {
    cout << each_edge.first << ": ";
    for (auto each_to : each_edge.second) {
      cout << each_to << " ";
    }
    cout << endl;
  }
}

void check(vector<vector<int>> expected, vector<vector<int>> actual) {
  sort(expected.begin(), expected.end());
  sort(actual.begin(), actual.end());

  for (int i=0;i<expected.size();i++) {
    for (int j=0;j<expected[i].size();j++) {

      if (expected[i][j] != actual[i][j]) {
        cout << "mismatch i: " << i << ", j: " << j;
        cout << " | " << expected[i][j] << " <=> " << actual[i][j] << endl;
        // return;
      }
    }
  }
}

int main() {
  // cout << "sample 1" << endl;
  // map<int, vector<int>> mp{{1, vector<int>{2}}, {2, vector<int>{1,3}}};
  // print(tarjan(3,mp));
  cout << "sample 2" << endl;
  map<int, vector<int>> mp2{
    {1, vector<int>{2}}, // A->B
    {2, vector<int>{3,11}},  // B->C, K
    {3, vector<int>{1,4}},
    {4, vector<int>{5}},
    {5, vector<int>{6, 11}},
    {6, vector<int>{7}},
    {7, vector<int>{4}},
    {8, vector<int>{9,10}}, // H->I,J
    {9, vector<int>{11}},
    {10, vector<int>{8}},
    {11, vector<int>{8}},
  };
  print(tarjan(11, mp2));
}