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

const int N = 3e5+5;
int a[N], b[N];
ii ba[N];

struct mergest {
  vector<vector<int>> st;
  mergest(int n, vector<int> &ar) {
    vector<vector<int>>(4*n, vector<int>()).swap(st);
    build(ar, 1, 0, n-1);
  }

  void build(vector<int> &ar, int p, int i, int j) {
    if (i == j) {
      st[p].push_back(ar[i]);
      return;
    }

    int k = (i+j)/2;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);
    pull(p);
  }

  void pull(int p) {
    vector<int> &left = st[p<<1];
    vector<int> &right = st[p<<1|1];

    vector<int> &res = st[p];
    int lsz = left.size(); int rsz = right.size();
    int l = 0;
    int r = 0;
    while(l < lsz || r < rsz) {
      if (l >= lsz) {
        res.push_back(right[r]);
        continue;
      }

      if (r >= rsz) {
        res.push_back(left[l]);
        continue;
      }

      if (left[l] < right[r]) {
        res.push_back(left[l]);
        l++;
      }
      else {
        res.push_back(right[r]);
        r++;
      }
    }
  }

  vector<int> query(int _i, int _j, int p, int i, int j) {
    if (_i <= i && j <= _j) {
      return st[p];
    }
    else if (_i > j || _j < i) {
      return {};
    }
    else {
      int k = (i+j)/2;
      vector<int> left = query(_i, _j, p<<1, i, k);
      vector<int> right = query(_i, _j, p<<1|1, k+1, j);

      vector<int> res;
      int lsz = left.size(); int rsz = right.size();
      int l = 0;
      int r = 0;
      while(l < lsz || r < rsz) {
        if (l >= lsz) {
          res.push_back(right[r]);
          continue;
        }

        if (r >= rsz) {
          res.push_back(left[l]);
          continue;
        }

        if (left[l] < right[r]) {
          res.push_back(left[l]);
          l++;
        }
        else {
          res.push_back(right[r]);
          r++;
        }
      }
      return res;
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  for (int i = 0; i < n; i++) ba[i] = {b[i], a[i]};
  sort(ba, ba+n);

  vector<int> ar;
  for (int i = 0; i < n; i++) ar.push_back(ba[i].second);
  mergest mst(n, ar);

  for (int i = 0; i < n; i++) {
    vector<int> res = mst.query(i, n-1, 1, 0, n-1);
    
  }
  
  return 0;
}
