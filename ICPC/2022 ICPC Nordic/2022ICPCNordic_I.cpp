#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  set<pair<int,int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    if (u > v) swap(u, v);
    edges.insert({u, v});
  }

  function<bool(int,int)> check = [&](int u, int v) {
    return edges.count({min(u,v), max(u, v)}) > 0;
  };

  vector<int> l(n, -1), r(n, n);
  r[0] = 1; l[1] = 0;

  int mid = 1;
  int rightmost = 1;
  for (int i = 2; i < n; i++) {
    bool has_edge = check(mid, i);
    if (r[mid] >= n) assert(l[mid] >= 0);
    if (l[mid] < 0) assert(r[mid] < n);
    if (l[mid] >= 0 && r[mid] < n) assert(check(mid, r[mid]) != check(mid, l[mid]));

    if (r[mid] >= n) {
      r[mid] = i;
      l[i] = mid;
      if (has_edge == check(mid, l[mid])) mid = i;
      rightmost = i;
    }
    else if (l[mid] < 0) {
      mid = rightmost; i--;
      continue;
    }
    else if (has_edge != check(mid, r[mid])) {
      int nmid = mid;
      if (has_edge == check(i, r[mid])) nmid = r[mid]; 
      else nmid = i;

      l[i] = mid; r[i] = r[mid];
      l[r[mid]] = i; r[mid] = i;
      mid = nmid;
    }
    else {
      int nmid = mid;
      if (has_edge == check(i, l[mid])) nmid = l[mid];
      else nmid = i;

      l[i] = l[mid]; r[i] = mid;
      r[l[mid]] = i; l[mid] = i;
      mid = nmid;
    }
  }
  
  int i = 0;
  while (i < n) {
    cout << i+1;
    cout << (r[i] < n ? " " : "\n");
    i = r[i];
  }

  return 0;
}