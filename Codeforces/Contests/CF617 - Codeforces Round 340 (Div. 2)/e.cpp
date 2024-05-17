#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Query {
  // change to smallest k such that 2^k >= n
  static inline int LOGN = 21;

  int id, l, r; ll hilbert_index;
  Query(int id, int l, int r) : id(id), l(l), r(r) {
    hilbert_index = hilbert_order(l, r, LOGN, 0); 
  }
  ll hilbert_order(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0;
    int hpow = 1 << (pow-1);
    int seg = ((x<hpow) ? ((y<hpow)?0:3) : ((y<hpow)?1:2));
    seg = (seg + rotate) & 3;
    const int rotate_delta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotate_delta[seg]) & 3;
    ll sub_sq_size = 1LL << (2*pow - 2);
    ll ans = seg * sub_sq_size;
    ll add = hilbert_order(nx, ny, pow-1, nrot);
    ans += (seg==1 || seg==2) ? add : (sub_sq_size-add-1);
    return ans; 
  }
  bool operator<(const Query& other) const {
    return hilbert_index < other.hilbert_index; 
  } 
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k; cin >> n >> m >> k;
  vector<ll> a(n), p(n+1);
  for (ll &x : a) cin >> x;
  for (int i = 0; i < n; i++) {
    p[i+1] = p[i]^a[i];
  }

  vector<Query> queries;
  for (int i = 0; i < m; i++) {
    int l, r; cin >> l >> r;
    l--;
    queries.push_back(Query(i, l, r));
  }
  sort(queries.begin(), queries.end());

  vector<ll> cnt(1<<21);
  int l = 0, r = 1;
  cnt[p[l]]++;
  ll c_ans = cnt[p[r]^k];
  cnt[p[r]]++;
  auto insert = [&](int i) {
    c_ans += cnt[k^p[i]];
    cnt[p[i]]++;
  };
  auto erase = [&](int i) {
    cnt[p[i]]--;
    c_ans -= cnt[k^p[i]];
  };

  vector<ll> ans(queries.size());
  for(const Query &q : queries) {  // [l,r] inclusive
    for(; r > q.r; r--)         erase(r);
    for(r = r+1; r <= q.r; r++) insert(r);
    r--;
    for(; l < q.l; l++)         erase(l);
    for(l = l-1; l >= q.l; l--) insert(l);
    l++; 
    ans[q.id] = c_ans;
  }
  for (int i = 0; i < m; i++) cout << ans[i] << "\n";


  
  return 0;
}