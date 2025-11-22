#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct interval {
  int in, out, idx;
  interval(int _in, int _out, int _idx) : in(_in), out(_out), idx(_idx) {}
  bool operator>(const interval &other) const {
    if (out == other.out) return in > other.in;
    return out > other.out;
  }
  bool operator<(const interval &other) const {
    if (out == other.out) return in < other.in;
    return out < other.out;
  }
};

struct UnionFind {
  vector<int> p;
  vector<set<interval>> intervals;
  UnionFind(int n) : p(n,-1), intervals(n) {}
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  bool is_same(int a, int b) { return find(a) == find(b); }
  int size(int a) { return -p[find(a)]; }
  bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (p[a] > p[b]) swap(a,b);
    p[a] += p[b]; p[b] = a;
    intervals[a].insert(intervals[b].begin(), intervals[b].end());
    return true;
  }
};

int get_top(stack<int> &s) {
  if (s.empty()) return INF;
  return s.top();
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n; cin >> n;
  vector<int> arr(n);
  for (int &x : arr) cin >> x;

  vector<int> in(n+1), out(n+1);
  vector<bool> in_stack(n+1);
  int current_value = 1;
  int time = 1;
  for (int i = 0; i < n; i++) {
    in_stack[arr[i]] = true;
    in[arr[i]] = time++;
    
    // pop out as soon as possible
    while (in_stack[current_value]) {
      out[current_value++] = time++;
    }
  }
  UnionFind uf(n);
  vector<int> ans(n,-1);
  bool possible = true;
  priority_queue<interval, vector<interval>, greater<interval>> pq;
  vector<vector<int>> adj_list(n);
  for (int i = 0; i < n; i++) {
    uf.intervals[i].insert(interval(in[arr[i]], out[arr[i]], i));
    while (!pq.empty() && pq.top().out < in[arr[i]]) {
      interval top = pq.top();
      int par = uf.find(top.idx);
      uf.intervals[par].erase(top);
      pq.pop();

      if (uf.intervals[par].size() > 0) {
        pq.push(*uf.intervals[par].begin());
      }
    }

    while (!pq.empty() && pq.top().out < out[arr[i]]) {
      interval top = pq.top();
      int par = uf.find(top.idx);
      int j = uf.intervals[par].begin()->idx;
      adj_list[j].push_back(i);
      adj_list[i].push_back(j);

      uf.unite(i, par);
      pq.pop();
    }

    int par = uf.find(i);
    pq.push(*uf.intervals[par].begin());
  }

  function<void(int,bool)> dfs = [&](int u, bool color) {
    if (ans[u] != -1) {
      if (ans[u] != color) possible = false;
      return;
    }
    ans[u] = color;

    for (int &v : adj_list[u]) {
      dfs(v, !color);
    }
  };

  for (int i = 0; i < n; i++) {
    if (ans[i] != -1) continue;
    dfs(i, 0);
  }

  // simulate
  stack<int> s_a, s_b;
  current_value = 1;
  for (int i = 0; i < n; i++) {
    if (ans[i]) s_a.push(arr[i]);
    else s_b.push(arr[i]);

    while (min(get_top(s_a), get_top(s_b)) == current_value) {
      if (get_top(s_a) == current_value) {
        s_a.pop();
        current_value++;
      }
      else {
        s_b.pop();
        current_value++;
      }
    }
  }



  if (current_value != n+1) cout << "IMPOSSIBLE\n";
  else {
    for (int i = 0; i < n; i++) {
      cout << (ans[i] ? 1 : 2) << "\n "[i+1<n];
    }
  }


  return 0;
}