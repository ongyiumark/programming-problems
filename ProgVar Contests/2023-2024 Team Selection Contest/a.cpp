#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> get_unique(vector<int> &ar) {
  sort(ar.begin(), ar.end());
  vector<int> res; res.push_back(ar[0]);
  for (int i = 1; i < ar.size(); i++) {
    if (ar[i] == ar[i-1]) continue;
    res.push_back(ar[i]);
  }
  return res;
}

unordered_map<int,int> compress(vector<int> &ar) {
  int n = ar.size();
  unordered_map<int,int> ret;
  for (int i = 0; i < n; i++) ret[ar[i]] = i;
  return ret; 
}

const int INF = 1e9+5;

struct SegmentTreeMin {
  int n;
  vector<int> st, lazy;
  SegmentTreeMin(int n) : n(n), st(4*n, INF), lazy(4*n) {}

  void pull(int p) { st[p] = min(st[p<<1], st[p<<1|1]); }
  void push(int p, int i, int j) {
    if (lazy[p]) {
      st[p] = lazy[p];
      if (i != j) {
        lazy[p<<1] = lazy[p];
        lazy[p<<1|1] = lazy[p];
      }
      lazy[p] = 0;
    }
  }

  void update(int l, int r, int v) { 
    update(l, r, v, 1, 0, n-1); 
  }
  void update(int l, int r, int v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p] = v;
      push(p, i, j);
    }
    else if (j < l || r < i) {}
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  int query(int l, int r) { return query(l, r, 1, 0, n-1); }
  int query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) { return st[p]; }
    else if (j < l || r < i) { return INF; }
    else {
      int k = (i+j)/2;
      return min(query(l, r, p<<1, i, k),query(l, r, p<<1|1, k+1, j));
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  // read input
  int d, s; cin >> d >> s;
  vector<pair<int,int>> drops;
  for (int i = 0; i < d; i++) {
    int x, y; cin >> x >> y;
    drops.push_back({x, y});
  }

  vector<tuple<int,int,int>> segments;
  for (int i = 0; i < s; i++) {
    int x1, x2, y; cin >> x1 >> x2 >> y;
    segments.push_back({x1, x2, y});
  }

  // collect coordinates
  vector<int> xcoords_tmp, ycoords_tmp;
  for (auto [x, y] : drops) {
    xcoords_tmp.push_back(x);
    ycoords_tmp.push_back(y);
  }

  for (auto [x1, x2, y] : segments) {
    xcoords_tmp.push_back(x1);
    xcoords_tmp.push_back(x2);
    ycoords_tmp.push_back(y);
  }

  // get unique coordinates and compress
  auto xcoords = get_unique(xcoords_tmp);
  auto ycoords = get_unique(ycoords_tmp);
  auto xcompress = compress(xcoords);
  auto ycompress = compress(ycoords);

  // collect by y-coordinate
  int y_sz = ycoords.size();
  vector ydrops(y_sz, vector<int>());
  vector ysegments(y_sz, vector<int>());
  for (int i = 0; i < d; i++) ydrops[ycompress[drops[i].second]].push_back(i);
  for (int i = 0; i < s; i++) ysegments[ycompress[get<2>(segments[i])]].push_back(i);

  // solve
  SegmentTreeMin stmin(xcoords.size());
  vector xdrops(xcoords.size(), vector<int>());
  vector<int> ans(d);

  // divide and conquer update
  function<void(int,int,int,int)> process_segment = [&](int l, int r, int y0, int y) {
    if (stmin.query(l, r) != y0) return;
    if (l != r) {
      int k = (l+r)/2;
      process_segment(l, k, y0, y);
      process_segment(k+1, r, y0, y);
      return;
    }
    if (xdrops[l].size() == 0) return; 
    int candidate = drops[xdrops[l].back()].second;
    if (candidate != y0) return;

    ans[xdrops[l].back()] = y;
    xdrops[l].pop_back();
    
    if (!xdrops[l].empty())
      stmin.update(l, l, drops[xdrops[l].back()].second);
    else
      stmin.update(l, l, INF);
  };

  for (int yidx = y_sz-1; yidx >= 0; yidx--) {
    // process drops
    for (int i : ydrops[yidx]) {
      auto [x, y] = drops[i];
      int compressed_x = xcompress[x];
      stmin.update(compressed_x, compressed_x, y);
      xdrops[compressed_x].push_back(i);
    }
    
    // process segments
    for (int i : ysegments[yidx]) {
      auto [x1, x2, y] = segments[i];
      int compressed_x1 = xcompress[x1];
      int compressed_x2 = xcompress[x2];
      int lowest = stmin.query(compressed_x1, compressed_x2);
      if (lowest == INF) continue;

      process_segment(compressed_x1, compressed_x2, lowest, ycoords[yidx]);
    }
  }
  
  for (int i = 0; i < d; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
