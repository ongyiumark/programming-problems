/*
  Let a_i be the position of the ith frog, and let b_i be where the ith frog's tongue ends.
  We sort by a_i. Then store b_i in as maximum segment tree.
  
  Suppose we want to find the frog that eats mosquito at position P.
  If left subtree is at least P, we go left. Otherwise, we go right.

  If a mosquito is not eaten, we put it in a set.
  Then, we only need to check the set every time a frog's tongue increases.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<pair<ll,ll>,ll> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+5;

int n, m;
ll s[N], e[N];
pii frogs[N];
pii ans[N];
map<ll,int> compress;
map<int,int> tree_to_idx;
multiset<pii> mosq;

struct segtree {
  ll *arr;
  segtree(int n) {
    arr = new ll[4*n];
    build(0,n-1,1);
  }

  void build(int l, int r, int p){
    if (l == r) {
      arr[p] = e[l];
      tree_to_idx[p] = l;
      return;
    }
    int k = (l+r)/2;
    build(l, k, 2*p);
    build(k+1, r, 2*p+1);
    arr[p] = max(arr[2*p], arr[2*p+1]);
  }

  void update(int l, int r, int p, int i, ll x) {
    int k = (l+r)/2;
    if (l == r) {
      arr[p] += x;
      return;
    }

    if (i <= k) update(l, k, 2*p, i, x);
    else update(k+1, r, 2*p+1, i, x);
    arr[p] = max(arr[2*p], arr[2*p+1]);
  }

  int find_idx(int l, int r, int p, ll x){
    if (l == r) return p;
    int k = (l+r)/2;
    if (arr[2*p] >= x) return find_idx(l, k, 2*p, x);
    else return find_idx(k+1,r, 2*p+1, x);
  }
};

void debug(){
    for (int i = 0; i < n; i++) {
      cout << s[i] << " " << e[i] << ",   ";
    }
    cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    ll x, t; cin >> x >> t;
    frogs[i] = {x, x+t};
    compress[x] = i;
    ans[i] = {0, t};
  }
  sort(frogs, frogs+n);
  for (int i = 0; i < n; i++){
    s[i] = frogs[i].first;
    e[i] = frogs[i].second;
  }
  segtree st(n);
  
  for (int i = 0; i < m; i++) {
    ll p, b; cin >> p >> b;
    int idx = tree_to_idx[st.find_idx(0,n-1,1,p)];

    if (s[idx] > p || e[idx] < p){
      mosq.insert({p,b});
      continue;
    }
    st.update(0, n-1, 1, idx, b);

    e[idx] += b;
    pii tmp = ans[compress[s[idx]]];
    ans[compress[s[idx]]] = {tmp.first+1, tmp.second+b};


    auto it = mosq.lower_bound({s[idx],-1});
    while (it != mosq.end()){
      if (e[idx] < it->first) break;
      st.update(0, n-1, 1, idx,it->second);
      e[idx] += it->second;
      pii tmp = ans[compress[s[idx]]];
      ans[compress[s[idx]]] = {tmp.first+1, tmp.second+it->second};
      mosq.erase(it);
      it = mosq.lower_bound({s[idx], -1});
    }
  }
  

  for (int i = 0; i < n; i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
  
  return 0;
}
