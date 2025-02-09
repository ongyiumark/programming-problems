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

struct res {
  ll two, five;

  res(ll a, ll b) : two(a), five(b) {}

  res operator+(const res& other) const {
    res ans = res(two+other.two, five+other.five);
    return ans;
  }
  res operator-(const res& other) const {
    res ans = res(two-other.two, five-other.five);
    return ans;
  }
};

ostream& operator<<(ostream& os, const res& r) {
  os << r.two << " " << r.five;
  return os;
}

ll solve(ll n, int p) {
  ll c = p;
  ll ans = 0;
  while(c <= n) {
    ans += n/c;
    c *= p;
  }
  return ans;
}

res solve(ll n) {
  return res(solve(n, 2), solve(n, 5));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n; cin >> n;
  res ans(0,0);
  if (n&1) ans = solve(n+1)-solve((n+1)/2)-res((n+1)/2, 0);
  else ans = solve(n/2)+res(n/2, 0);
  cout << min(ans.five, ans.two) << "\n";
  return 0;
}
