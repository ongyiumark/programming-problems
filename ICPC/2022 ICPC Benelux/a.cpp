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

const int N = 1500+5;
ll n, k, x; 
ll a[N];

ll ans = 1e18;
ld bans = 1e18;
vector<ll> nums;

void brute(int i, int rem) {
  if (i == n) {
    ll total = 0;
    for (int xx : nums) total += xx;
    ld avg = (ld)total/nums.size();
    bans = min(fabs(avg-x), bans);
    
    return;
  }

  // remove
  if (rem > 0) brute(i+1, rem-1);

  // dont remove
  nums.push_back(a[i]);
  brute(i+1, rem);
  nums.pop_back();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) cin >> a[i];

  cout << setprecision(40) << fixed;
  if (k <= 4) {
    brute(0, k);

    cout << bans << "\n";
    return 0;
  }
  
  
  return 0;
}
