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

struct obs {
  ll x, y;
};

struct mergetree {
  int n;
  vector<vector<ll>> vals;
  
  mergetree(int _n, vector<ll> &ar) {
    int n = _n;
    vector<vector<ll>>(4*n).swap(vals);
    
    build(ar, 0, n-1, 1);
  }

  void pull(int p) {
    vector<ll> &left = vals[p<<1];
    vector<ll> &right = vals[p<<1|1];
    vector<ll> &res = vals[p];

    res.resize(left.size() + right.size());
    merge(left.begin(), left.end(), right.begin(), right.end(), res.begin());
  } 

  void build(vector<ll> &ar, int i, int j, int p) {
    if (i == j) {
      vals[p].push_back(ar[i]);
    }
    else {
      int k = (i+j)/2;
      build(ar, i, k, p<<1);
      build(ar, k+1, j, p<<1|1);
      pull(p);
    }
  }

  ll query(int l, int r, ll y, int p, int i, int j) {
    if (l <= i && j <= r) {
      return lower_bound(vals[p].begin(), vals[p].end(), y) - vals[p].begin();
    }
    else if (j < l || r < i) {
      return 0;
    }
    else {
      int k = (i+j)/2;
      return query(l, r, y, p<<1, i, k) + query(l, r, y, p<<1|1, k+1, j);
    }
  }
};

bool operator<(const obs &left, const obs &right) {
  if (left.x == right.x) return left.y < right.y;
  return left.x < right.x;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll h, w, m;
  cin >> h >> w >> m;

  vector<ll> loX(h+1, w+1), loY(w+1, h+1);
  vector<vector<ll>> nX(h+1), nY(w+1);

  vector<obs> o(m);
  for (int i = 0; i < m; i++) {
    cin >> o[i].x >> o[i].y;

    loX[o[i].x] = min(loX[o[i].x], o[i].y);
    loY[o[i].y] = min(loY[o[i].y], o[i].x);
  }

  ll unreach = (h+1 - loY[1])*(w+1 - loX[1]);
  for (int i = 1; i < loX[1]; i++) {
    if (loY[i] >= loY[1]) unreach += (h+1 - loY[i]);
    else unreach += (h+1 - loY[1]);
  }
  for (int i = 1; i < loY[1]; i++) {
    if (loX[i] >= loX[1]) unreach += (w+1 - loX[i]);
    else unreach += (w+1 - loX[1]);
  }

  vector<obs> no;
  for (int i = 0; i < m; i++) {
    if (o[i].x < loY[1] && o[i].y < loX[1]) {
      no.push_back(o[i]);
      nX[o[i].x].push_back(o[i].y);
      nY[o[i].y].push_back(o[i].x);
    }
  }

  for (int i = 1; i < loX[1]; i++) sort(nY[i].begin(), nY[i].end());
  for (int i = 1; i < loY[1]; i++) sort(nX[i].begin(), nX[i].end());

  sort(no.begin(), no.end());
  ll sz = no.size();

  set<obs> tmp1, tmp2;
  for (int i = 0; i < sz; i++) {
    tmp1.insert({no[i].x, loX[no[i].x]});
    tmp2.insert({loY[no[i].y], no[i].y});
  }

  vector<obs> n1, n2;
  vector<ll> ar;

  for (obs t : tmp1) {
    n1.push_back(t);
    ar.push_back(t.y);
  }

  for (obs t : tmp2) {
    n2.push_back(t);
  }

  int sz1 = n1.size();
  int sz2 = n2.size();

  if (sz1) {
    mergetree mst(sz1, ar);
    for (int i = 0, j = 0; i < sz2 && j < sz1; i++) {
      while(j < sz1 && n2[i].x >= n1[j].x) j++;
      if (j >= sz1) break;

      unreach += mst.query(j, sz1-1, n2[i].y, 1, 0, sz1-1);
    }
  }

  for (int i = 0; i < sz; i++) {
    if (loX[no[i].x] < no[i].y && loY[no[i].y] < no[i].x) unreach--;
  }
  cout << h*w-unreach-sz << "\n";

  return 0;
}
