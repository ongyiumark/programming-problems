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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, x, m;
  cin >> n >> x >> m;
  ll og_x = x;

  // find cycle
  vector<int> vis(m, -1);
  ll time = 0;
  vis[x] = time;
  while (vis[x*x%m] == -1) {
    x = x*x%m;
    vis[x] = ++time;
  }
  ll cycle = vis[x] - vis[x*x%m] + 1;

  // add before cycle
  ll curr_x = og_x;
  ll cycle_start = x*x%m;
  ll total = 0;
  while(curr_x != cycle_start && n > 0) {
    total += curr_x;
    curr_x = curr_x*curr_x%m;
    n--;
  }

  // add cycle
  ll cycle_sum = curr_x;
  curr_x = curr_x*curr_x%m;
  while (curr_x != cycle_start) {
    cycle_sum += curr_x;
    curr_x = curr_x*curr_x%m;
  }
  total += n / cycle * cycle_sum;

  // add after cycle
  n %= cycle;
  curr_x = cycle_start;
  while(n--) {
    total += curr_x;
    curr_x = curr_x*curr_x%m;
  }
  cout << total << "\n";
  
  return 0;
}
