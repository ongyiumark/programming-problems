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

  const int INF = 1e9;
  int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, n; cin >> h >> n;
    vector<int> dp(h+5, INF);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= h; j++) {
        dp[min(j+a[i], h)] = min(dp[min(j+a[i], h)], dp[j]+b[i]);
      }
    }

    cout << dp[h] << "\n";    
    return 0;
  }
