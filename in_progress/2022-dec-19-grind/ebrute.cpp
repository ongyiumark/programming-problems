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

const int N = 2e5+5;
const int P = 1e4+5;
ll dp[N];
ll cnt[P];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, p;
  string s;
  cin >> n >> p >> s;

  memset(cnt, 0, sizeof cnt);
  memset(dp, 0, sizeof dp);

  ll total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      string t = s.substr(i, j-i+1);
      ll curr = 0;
      for (char &ch : t) {
        curr = (curr*10 + (ch-'0'))%p;
      }
      total += (curr==0);
    }
  }

  cout << total << "\n";
 

  return 0;
}
