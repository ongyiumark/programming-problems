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

ll modpow(ll b, ll e, ll m) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%m;
    b = b*b%m;
    e >>= 1;
  }
  return ans;
}

template<int B, ll... Ms>
struct rolling_hash {
  vector<ll> m, h;
  ll b;

  rolling_hash() : b(B) { 
    m = {Ms...}; 
    vector<ll>(m.size(), 0).swap(h);
  }

  int size() { return m.size(); }
  ll operator()(const int& i) const { return m[i]; }
  ll operator[](const int& i) const { return h[i]; }
  friend ostream& operator<<(ostream &os, const rolling_hash<B, Ms...> &rh) {
    int n = rh.size();
    for (int i = 0; i < n; i++) {
      os << rh[i];
      if (i+1 < n) cout << " ";
    }
    return os;
  }
  bool operator<(const rolling_hash<B, Ms...>& other) const {
    int n = m.size();
    for (int i = 0; i < n; i++) {
      if (h[i] < other[i]) return true;
      if (h[i] > other[i]) return false;
    }
    return false;
  }

  void add(ll x) {
    int n = m.size();
    for (int i = 0; i < n; i++) {
      h[i] *= b;
      h[i] += x;
      h[i] %= m[i];
    }
  }

  void remove(ll x, ll k) {
    int n = m.size();
    for (int i = 0; i < n; i++) {
      h[i] -= modpow(b, k-1, m[i])*x%m[i];
      h[i] %= m[i];
      if (h[i] < 0) h[i] += m[i];
    }
  }
};

bool check(string &s, int len) {
  if (len == 0) return true;

  int n = s.size();
  const ll mod1 = 1e9+7, mod2 = 1e9+9;

  rolling_hash<137, mod1, mod2> rh;
  for (int i = 0; i < len; i++) rh.add(s[i]-'a'+1);

  map<rolling_hash<137, mod1, mod2>, int> table;
  table[rh] = 0;
  for (int i = 0; i+len < n; i++) {
    rh.remove(s[i]-'a'+1, len);
    rh.add(s[i+len]-'a'+1);

    if (table.count(rh) > 0) {
      if (table[rh] <= i+1-len) {
        assert(s.substr(table[rh], len)==s.substr(i+1, len)) ;
        return true;
      }
    }
    else table[rh] = i+1;
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  string s; cin >> s;

  int lo = 0;
  int hi = n;
  int ans = 0;

  while (lo <= hi) {
    int mid = hi-(hi-lo)/2;
    if (check(s, mid)) {
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }

  cout << ans << "\n";
  
  return 0;
}
