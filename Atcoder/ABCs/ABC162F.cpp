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

const ll INF = 1e18;
const int N = 2e5+5;
int a[N];
int n;
map<ii, ll> memo;

ll solve(int i, int x) {
  if (memo.find({i, x}) != memo.end()) return memo[{i,x}];
  ll &ans = memo[{i,x}];
  if (x == 0) ans = 0;
  else if (n-i <= 2*x-1) ans = a[i] + solve(i+2, x-1);
  else ans = max(a[i] + solve(i+2, x-1), solve(i+1, x));

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << solve(0, n/2) << "\n";
  
  return 0;
}
