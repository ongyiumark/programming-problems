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

string s;
ll k;
int n;

struct myhash {
  template<class T>
  void hash_combine(size_t &seed, T const& v) const {
    seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
  }

  size_t operator()(const tuple<int,ll,bool,bool> &k) const {
    size_t seed = 0;
    hash_combine(seed, get<0>(k));
    hash_combine(seed, get<1>(k));
    hash_combine(seed, get<2>(k));
    hash_combine(seed, get<3>(k));

    return seed;
  }
};

unordered_map<const tuple<int,ll,bool, bool>, ll, myhash> memo;

ll solve(int i, ll j, bool lower, bool start) {
  if (memo.find({i, j, lower, start}) != memo.end()) return memo[{i, j, lower, start}];
  
  ll &ans = memo[{i, j, lower, start}];
  if (i == n) return ans = (j <= k);

  ans = 0;
  if (!start) {
    ans = solve(i+1, j, 1, 0);
    for (ll l = 1; l <= (lower ? 9 : s[i]-'0'); l++) ans += solve(i+1, j*l, lower || (l < s[i]-'0'), 1);
  }
  else {
    for (ll l = 0; l <= (lower ? 9 : s[i]-'0'); l++) ans += solve(i+1, j*l, lower || (l < s[i]-'0'), 1);
  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> k;
  n = s.size();
  cout << solve(0, 1, 0, 0)-1 << "\n";
  
  return 0;
}
